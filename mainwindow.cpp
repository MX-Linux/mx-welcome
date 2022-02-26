/**********************************************************************
 *  mainwindow.cpp
 **********************************************************************
 * Copyright (C) 2015 MX Authors
 *
 * Authors: Adrian
 *          Paul David Callahan
 *          Dolphin Oracle
 *          MX Linux <http://mxlinux.org>
 *
 * This file is part of mx-welcome.
 *
 * mx-welcome is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mx-welcome is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mx-welcome.  If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QTextEdit>

#include "flatbutton.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "version.h"

MainWindow::MainWindow(const QCommandLineParser& arg_parser, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    qDebug().noquote() << QCoreApplication::applicationName() << "version:" << VERSION;
    ui->setupUi(this);
    setWindowFlags(Qt::Window); // for the close, min and max buttons
    setup();

    ui->tabWidget->setCurrentIndex(0);
    if (arg_parser.isSet("about"))
        ui->tabWidget->setCurrentIndex(1);

    if (arg_parser.isSet("test")) {
        ui->labelLoginInfo->show();
        ui->buttonSetup->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// setup versious items first time program runs
void MainWindow::setup()
{
    version = getVersion("mx-welcome");
    this->setWindowTitle(tr("MX Welcome"));

    QString old_conf_file = QDir::homePath() + "/.config/" + qApp->applicationName() + ".conf";
    if (QFileInfo::exists(old_conf_file)) {
        QSettings old_settings(qApp->applicationName());
        user_settings.setValue("AutoStartup", old_settings.value("AutoStartup", false).toBool());
        QFile::remove(old_conf_file);
    }
    bool autostart = user_settings.value("AutoStartup", false).toBool();
    ui->checkBox->setChecked(autostart);
    if (!autostart) QFile::remove(QDir::homePath() + "/.config/autostart/mx-welcome.desktop");

    // setup title block & icons
    QSettings settings("/usr/share/mx-welcome/mx-welcome.conf", QSettings::NativeFormat);
    QSettings settingsusr("/etc/share/mx-welcome/mx-welcome.conf", QSettings::NativeFormat);
    QString DISTRO = settings.value("DISTRO").toString();
    if ( DISTRO.isEmpty()) {
        DISTRO = settingsusr.value("DISTRO").toString();
    }
    QString CODENAME = settings.value("CODENAME").toString();
    if ( CODENAME.isEmpty()) {
        CODENAME = settingsusr.value("CODENAME").toString();
    }

    QString HEADER = settings.value("HEADER").toString();
    if ( HEADER.isEmpty()) {
        HEADER = settingsusr.value("HEADER").toString();
    }

    QString LOGO = settings.value("LOGO").toString();
    if ( LOGO.isEmpty()) {
        LOGO = settingsusr.value("LOGO").toString();
    }

    QString SUPPORTED = settings.value("SUPPORTED").toString();
    if ( SUPPORTED.isEmpty()) {
        SUPPORTED = settingsusr.value("SUPPORTED").toString();
    }

    TOSCMD=settings.value("TOSCMD").toString();
    if ( TOSCMD.isEmpty()) {
        TOSCMD  = settingsusr.value("TOSCMD").toString();
    }
    QString TOSTEXT=settings.value("TOSTEXT").toString();
    if ( TOSTEXT.isEmpty()) {
        TOSTEXT = settingsusr.value("TOSTEXT").toString();
    }
    if ( ! TOSTEXT.isEmpty() ){
        ui->buttonFAQ->setText(TOSTEXT);
    }

    QString SETUP = settings.value("1icon").toString();
    if ( SETUP.isEmpty()) {
        SETUP = settingsusr.value("1icon").toString();
    }
    QString SETUPTEXT=settings.value("1text").toString();
    if ( SETUPTEXT.isEmpty()) {
        SETUPTEXT = settingsusr.value("1text").toString();
    }
    if ( ! SETUPTEXT.isEmpty() ){
        ui->buttonSetup->setText(SETUPTEXT);
    }
    SETUPCMD=settings.value("1command").toString();
    if ( SETUPCMD.isEmpty()) {
        SETUPCMD = settingsusr.value("1command").toString();
    }

    QString FAQ = settings.value("2icon").toString();
    if ( FAQ.isEmpty()) {
        FAQ = settingsusr.value("2icon").toString();
    }
    QString FAQTEXT=settings.value("2text").toString();
    if ( FAQTEXT.isEmpty()) {
        FAQTEXT = settingsusr.value("2text").toString();
    }
    if ( ! FAQTEXT.isEmpty() ){
        ui->buttonFAQ->setText(FAQTEXT);
    }
    FAQCMD=settings.value("2command").toString();
    if ( FAQCMD.isEmpty()) {
        FAQCMD = settingsusr.value("2command").toString();
    }

    QString FORUMS = settings.value("3icon").toString();
    if ( FORUMS.isEmpty()) {
        FORUMS = settingsusr.value("3icon").toString();
    }
    QString FORUMTEXT=settings.value("3text").toString();
    if ( FORUMTEXT.isEmpty()) {
        FORUMTEXT = settingsusr.value("3text").toString();
    }
    if ( ! FORUMTEXT.isEmpty() ){
        ui->buttonForum->setText(FORUMTEXT);
    }
    FORUMCMD=settings.value("3command").toString();
    if ( FORUMCMD.isEmpty()) {
        FORUMCMD = settingsusr.value("3command").toString();
    }


    QString MANUAL = settings.value("4icon").toString();
    if ( MANUAL.isEmpty()) {
        MANUAL = settingsusr.value("4icon").toString();
    }
    QString MANUALTEXT=settings.value("4text").toString();
    if ( MANUALTEXT.isEmpty()) {
        MANUALTEXT = settingsusr.value("4text").toString();
    }
    if ( ! MANUALTEXT.isEmpty() ){
        ui->buttonManual->setText(MANUALTEXT);
    }
    MANUALCMD=settings.value("4command").toString();
    if ( MANUALCMD.isEmpty()) {
        MANUALCMD = settingsusr.value("4command").toString();
    }

    QString VIDEOS = settings.value("5icon").toString();
    if ( VIDEOS.isEmpty()) {
        VIDEOS = settingsusr.value("5icon").toString();
    }
    QString VIDEOTEXT=settings.value("5text").toString();
    if ( VIDEOTEXT.isEmpty()) {
        VIDEOTEXT = settingsusr.value("5text").toString();
    }
    if ( ! VIDEOTEXT.isEmpty() ){
        ui->buttonVideo->setText(VIDEOTEXT);
    }
    VIDEOCMD=settings.value("5command").toString();
    if ( VIDEOCMD.isEmpty()) {
        VIDEOCMD = settingsusr.value("5command").toString();
    }

    QString WIKI = settings.value("6icon").toString();
    if ( WIKI.isEmpty()) {
        WIKI = settingsusr.value("6icon").toString();
    }
    QString WIKITEXT=settings.value("6text").toString();
    if ( WIKITEXT.isEmpty()) {
        WIKITEXT = settingsusr.value("6text").toString();
    }
    if ( ! WIKITEXT.isEmpty() ){
        ui->buttonWiki->setText(WIKITEXT);
    }
    WIKICMD=settings.value("6command").toString();
    if ( WIKICMD.isEmpty()) {
        WIKICMD = settingsusr.value("6command").toString();
    }

    QString CONTRIBUTE = settings.value("7icon").toString();
    if ( CONTRIBUTE.isEmpty()) {
        CONTRIBUTE = settingsusr.value("7icon").toString();
    }
    QString CONTRIBUTETEXT=settings.value("7text").toString();
    if ( CONTRIBUTETEXT.isEmpty()) {
        CONTRIBUTETEXT = settingsusr.value("7text").toString();
    }
    if ( ! CONTRIBUTETEXT.isEmpty() ){
        ui->buttonContribute->setText(CONTRIBUTETEXT);
    }
    CONTRIBUTECMD=settings.value("7command").toString();
    if ( CONTRIBUTECMD.isEmpty()) {
        CONTRIBUTECMD = settingsusr.value("7command").toString();
    }

    QString TOOLS = settings.value("8icon").toString();
    if ( TOOLS.isEmpty()) {
        TOOLS = settingsusr.value("8icon").toString();
    }
    QString TOOLSTEXT=settings.value("8text").toString();
    if ( TOOLSTEXT.isEmpty()) {
        TOOLSTEXT = settingsusr.value("8text").toString();
    }
    if ( ! TOOLSTEXT.isEmpty() ){
        ui->buttonTools->setText(TOOLSTEXT);
    }
    TOOLSCMD=settings.value("8command").toString();
    if ( TOOLSCMD.isEmpty()) {
        TOOLSCMD = settingsusr.value("8command").toString();
    }

    QString PACKAGEINSTALLER = settings.value("9icon").toString();
    if ( PACKAGEINSTALLER.isEmpty()) {
        PACKAGEINSTALLER = settingsusr.value("9icon").toString();
    }
    QString PACKAGEINSTALLERTEXT=settings.value("9text").toString();
    if ( PACKAGEINSTALLERTEXT.isEmpty()) {
        PACKAGEINSTALLERTEXT = settingsusr.value("9text").toString();
    }
    if ( ! PACKAGEINSTALLERTEXT.isEmpty() ){
        ui->buttonPackageInstall->setText(PACKAGEINSTALLERTEXT);
    }
    PACKAGEINSTALLERCMD=settings.value("9command").toString();
    if ( PACKAGEINSTALLERCMD.isEmpty()) {
        PACKAGEINSTALLERCMD = settingsusr.value("9command").toString();
    }

    QString TWEAK = settings.value("10icon").toString();
    if ( TWEAK.isEmpty()) {
        TWEAK = settingsusr.value("10icon").toString();
    }
    QString TWEAKTEXT=settings.value("10text").toString();
    if ( TWEAKTEXT.isEmpty()) {
        TWEAKTEXT = settingsusr.value("10text").toString();
    }
    if ( ! TWEAKTEXT.isEmpty() ){
        ui->buttonPanelOrient->setText(TWEAKTEXT);
    }
    TWEAKCMD=settings.value("10command").toString();
    if ( TWEAKCMD.isEmpty()) {
        TWEAKCMD = settingsusr.value("10command").toString();
    }

    QString TOUR = settings.value("11icon").toString();
    if ( TOUR.isEmpty()) {
        TOUR = settingsusr.value("11icon").toString();
    }
    QString TOURTEXT=settings.value("11text").toString();
    if ( TOURTEXT.isEmpty()) {
        TOURTEXT = settingsusr.value("11text").toString();
    }
    if ( ! TOURTEXT.isEmpty() ){
        ui->buttonTour->setText(TOURTEXT);
    }
    TOURCMD=settings.value("11command").toString();
    if ( TOURCMD.isEmpty()) {
        TOURCMD = settingsusr.value("11command").toString();
    }

    // hide tour if not present AND TOURTEXT.ISEMPTY
    if ( TOURTEXT.isEmpty() ){
        if (!QFile::exists("/usr/bin/mx-tour")) {
            ui->buttonTour->hide();
        }
    }
    QString SHOWLIVEUSERINFO = settings.value("SHOWLIVEUSERINFO", "true").toString();
    if ( SHOWLIVEUSERINFO.isEmpty()) {
        SHOWLIVEUSERINFO = settingsusr.value("SHOWLIVEUSERINFO", "true").toString();
    }
    //qDebug() << "hide value: " << SHOWLIVEUSERINFO;
    bool LIVEUSERINFOSHOW = true;
    if ( SHOWLIVEUSERINFO == "false" ){
        LIVEUSERINFOSHOW = false;
    }

    ui->labelLoginInfo->setText("<p align=\"center\">" + tr("User demo, password:") + "<b> demo</b>. " + tr("Superuser root, password:") + "<b> root</b>." + "</p>");

    // if running live
    QString test = runCmd("df -T / |tail -n1 |awk '{print $2}'").output;
    if ( test == "aufs" || test == "overlay") {
        ui->checkBox->setVisible(false);
        ui->labelLoginInfo->setVisible(LIVEUSERINFOSHOW);
    } else {
        ui->labelLoginInfo->setVisible(false);
        ui->buttonSetup->setVisible(false);
    }

    //check /etc/lsb-release file, overridable
    QString CHECKLSB_RELEASE = settings.value("CHECKLSB_RELEASE", "true").toString();
    if ( CHECKLSB_RELEASE.isEmpty()) {
        CHECKLSB_RELEASE = settingsusr.value("CHECKLSB_RELEASE", "true").toString();
    }

    bool CHECKLSB = true;
    if ( CHECKLSB_RELEASE == "false" ){
        CHECKLSB = false;
    }

    if (CHECKLSB) {
        if ( QFileInfo("/etc/lsb-release").exists() ) {
            QSettings lsb("/etc/lsb-release", QSettings::NativeFormat);
            QString MAINDISTRO = lsb.value("DISTRIB_ID").toString();
            CODENAME = lsb.value("DISTRIB_CODENAME").toString();
            QString DISTRIB_RELEASE = lsb.value("DISTRIB_RELEASE").toString();
            DISTRO = MAINDISTRO + "-" + DISTRIB_RELEASE;
        }
    }
    QString debian_version;
    QString mxfluxbox_version;

    QFile file("/etc/debian_version");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(nullptr, tr("Error"), file.errorString());

    QTextStream in(&file);
    debian_version = in.readLine();
    file.close();

    ui->LabelDebianVersion->setText(debian_version);

    ui->labelSupportUntil->setText(SUPPORTED);

    QString DESKTOP = runCmd("LANG=C inxi -c 0 -S ").output.trimmed().section(":", 5, 5).section("\n", 0, 0);
    if (DESKTOP.contains("Fluxbox")) {
        isfluxbox = true;
        QFile file("/etc/mxfb_version");
        if (file.exists()) {
            if (!file.open(QIODevice::ReadOnly))
                QMessageBox::information(nullptr, tr("Error"), file.errorString());
            QTextStream in(&file);
            mxfluxbox_version = in.readLine();
            qDebug() << "mxfluxbox" << mxfluxbox_version;
            file.close();
            if (!mxfluxbox_version.isEmpty())
                DESKTOP.append(" " + mxfluxbox_version);
        }
    }

    ui->labelDesktopVersion->setText(DESKTOP);

    ui->labelTitle->setText(tr("<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">%1 &quot;%2&quot;</span></p></body></html>").arg(DISTRO).arg(CODENAME));
    if (QFile::exists(HEADER))
        ui->labelgraphic->setPixmap(HEADER);

    // setup icons
    //ui->buttonCodecs->setIcon(QIcon(CODECS));
    ui->buttonContribute->setIcon(QIcon(CONTRIBUTE));
    ui->buttonFAQ->setIcon(QIcon(FAQ));
    ui->buttonForum->setIcon(QIcon(FORUMS));
    ui->labelMX->setPixmap(QPixmap(LOGO));
    ui->buttonPackageInstall->setIcon(QIcon(PACKAGEINSTALLER));
    ui->buttonPanelOrient->setIcon(QIcon(TWEAK));
    ui->buttonSetup->setIcon(QIcon(SETUP));
    ui->buttonTools->setIcon(QIcon(TOOLS));
    ui->buttonManual->setIcon(QIcon(MANUAL));
    ui->buttonVideo->setIcon(QIcon(VIDEOS));
    ui->buttonWiki->setIcon(QIcon(WIKI));
    ui->buttonTour->setIcon(QIcon(TOUR));

    // setup about labels
    ui->labelMXversion->setText(DISTRO);

    settabstyle();
    this->adjustSize();
}

// Util function for getting bash command output and error code
Result MainWindow::runCmd(QString cmd)
{
    QEventLoop loop;
    QProcess proc;
    proc.setProcessChannelMode(QProcess::MergedChannels);
    connect(&proc, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), &loop, &QEventLoop::quit);
    proc.start("/bin/bash", QStringList() << "-c" << cmd);
    loop.exec();
    return { proc.exitCode(), proc.readAll().trimmed() };
}

// Get version of the program
QString MainWindow::getVersion(QString name)
{
    return runCmd("dpkg-query -f '${Version}' -W " + name).output;
}

// About button clicked
void MainWindow::on_buttonAbout_clicked()
{
    this->hide();
    QMessageBox msgBox(QMessageBox::NoIcon,
        tr("About MX Welcome"), "<p align=\"center\"><b><h2>" + tr("MX Welcome") + "</h2></b></p><p align=\"center\">" + tr("Version: ") + version + "</p><p align=\"center\"><h3>" + tr("Program for displaying a welcome screen in MX Linux") + "</h3></p><p align=\"center\"><a href=\"http://www.mxlinux.org/mx\">http://www.mxlinux.org/mx</a><br /></p><p align=\"center\">" + tr("Copyright (c) MX Linux") + "<br /><br /></p>");
    QPushButton* btnLicense = msgBox.addButton(tr("License"), QMessageBox::HelpRole);
    QPushButton* btnChangelog = msgBox.addButton(tr("Changelog"), QMessageBox::HelpRole);
    QPushButton* btnCancel = msgBox.addButton(tr("Cancel"), QMessageBox::NoRole);
    btnCancel->setIcon(QIcon::fromTheme("window-close"));

    msgBox.exec();

    if (msgBox.clickedButton() == btnLicense) {
        QString cmd = QString("mx-viewer file:///usr/share/doc/mx-welcome/license.html '%1'").arg(tr("MX Welcome"));
        system(cmd.toUtf8());
    } else if (msgBox.clickedButton() == btnChangelog) {
        QDialog* changelog = new QDialog(this);
        changelog->resize(600, 500);

        QTextEdit* text = new QTextEdit;
        text->setReadOnly(true);
        text->setText(runCmd("zless /usr/share/doc/" + QFileInfo(QCoreApplication::applicationFilePath()).fileName() + "/changelog.gz").output);

        QPushButton* btnClose = new QPushButton(tr("&Close"));
        btnClose->setIcon(QIcon::fromTheme("window-close"));
        connect(btnClose, &QPushButton::clicked, changelog, &QDialog::close);

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(text);
        layout->addWidget(btnClose);
        changelog->setLayout(layout);
        changelog->exec();
    }
    this->show();
}

// Add/remove autostart at login
void MainWindow::on_checkBox_clicked(bool checked)
{
    user_settings.setValue("AutoStartup", checked);
    if (checked)
        QFile::copy("/usr/share/mx-welcome/mx-welcome.desktop", QDir::homePath() + "/.config/autostart/mx-welcome.desktop");
    else
        QFile::remove(QDir::homePath() + "/.config/autostart/mx-welcome.desktop");
}

// Start MX-Tools
void MainWindow::on_buttonTools_clicked()
{
    QString cmd = "mx-tools&";
    if ( ! TOOLSCMD.isEmpty() ){
        cmd = TOOLSCMD;
    }
    system(cmd.toUtf8());
}

// Launch Manual in browser
void MainWindow::on_buttonManual_clicked()
{
    QString cmd;
    if (isfluxbox)
        cmd = "mxfb-help&";
    else
        cmd = "mx-manual&";
    if ( ! MANUALCMD.isEmpty() )
        cmd = MANUALCMD;

    system(cmd.toUtf8());
}

// Launch Forum in browser
void MainWindow::on_buttonForum_clicked()
{
    QString cmd = "xdg-open http://forum.mxlinux.org/index.php";
    if ( ! FORUMCMD.isEmpty() ){
        cmd = FORUMCMD;
    }
    system(cmd.toUtf8());
}

// Launch Wiki in browser
void MainWindow::on_buttonWiki_clicked()
{
    QString cmd = "xdg-open http://www.mxlinux.org/wiki";
    if ( ! WIKICMD.isEmpty() ){
        cmd = WIKICMD;
    }
    system(cmd.toUtf8());
}

// Launch Video links in browser
void MainWindow::on_buttonVideo_clicked()
{
    QString cmd = "xdg-open http://www.mxlinux.org/videos/";
    if ( ! VIDEOCMD.isEmpty() ){
        cmd = VIDEOCMD;
    }
    system(cmd.toUtf8());
}

// Launch Contribution page
void MainWindow::on_buttonContribute_clicked()
{
    QString cmd = "xdg-open http://www.mxlinux.org/donate";
    if ( ! CONTRIBUTECMD.isEmpty() ){
        cmd = CONTRIBUTECMD;
    }
    system(cmd.toUtf8());
}

void MainWindow::on_buttonPanelOrient_clicked()
{
    QString cmd = "mx-tweak&";
    if ( ! TWEAKCMD.isEmpty() ){
        cmd = TWEAKCMD;
    }
    system(cmd.toUtf8());
}

void MainWindow::on_buttonPackageInstall_clicked()
{
    QString cmd = "su-to-root -X -c mx-packageinstaller&";
    if ( ! PACKAGEINSTALLERCMD.isEmpty() ){
        cmd = PACKAGEINSTALLERCMD;
    }
    system(cmd.toUtf8());
}

void MainWindow::on_buttonFAQ_clicked()
{
    QString cmd = "mx-faq&";
    if ( ! FAQCMD.isEmpty() ){
        cmd = FAQCMD;
    }
    system(cmd.toUtf8());
}

void MainWindow::on_buttonSetup_clicked()
{
    QString cmd = "minstall-launcher&";
    if ( ! SETUPCMD.isEmpty() ){
        cmd = SETUPCMD;
    }
    system(cmd.toUtf8());
}

void MainWindow::on_buttonTOS_clicked()
{
    QString cmd = "xdg-open https://mxlinux.org/terms-of-use/";
    if ( ! TOSCMD.isEmpty() ){
        cmd = TOSCMD;
    }
    system(cmd.toUtf8());
}

void MainWindow::on_ButtonQSI_clicked()
{
    system("x-terminal-emulator -e bash -c \"/usr/bin/quick-system-info-mx\" &");
}

void MainWindow::shortsysteminfo()
{
    ui->textBrowser->setText(runCmd("LANG=C inxi -c 0").output);
}
void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 1)
        shortsysteminfo();
    settabstyle();
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    settabstyle();
}

void MainWindow::settabstyle()
{
    QString tw = QString::number(ui->tabWidget->width() / 2 - 1);
    //qDebug() << "width" << ui->tabWidget->width() << "tw" << tw;
    ui->tabWidget->setStyleSheet(""
                                 "QTabBar::tab:!selected{width: "
        + tw + "px; background:  rgba(140, 135, 135, 50)}"
               ""
               "QTabBar::tab:selected{width: "
        + tw + "px}"
               "");
}

void MainWindow::on_buttonTour_clicked()
{
    QString cmd = "mx-tour&";
    if ( ! TOURCMD.isEmpty() ){
        cmd = TOURCMD;
    }
    system(cmd.toUtf8());
}
