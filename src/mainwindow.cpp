/**********************************************************************
 *  mainwindow.cpp
 **********************************************************************
 * Copyright (C) 2015-2024 MX Authors
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

#include <QDir>
#include <QDesktopServices>
#include <QFileInfo>
#include <QProcess>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QTextEdit>
#include <QTimer>
#include <QUrl>

#include "about.h"
#include "flatbutton.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "version.h"

namespace
{
void openUrl(const QString &url)
{
    QDesktopServices::openUrl(QUrl(url));
}
}

MainWindow::MainWindow(const QCommandLineParser& arg_parser, QWidget* parent)
    : QDialog(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window); // For the close, min and max buttons
    connect(ui->buttonCancel, &QPushButton::pressed, this, &MainWindow::close);
    setup();

    ui->tabWidget->setCurrentIndex(0);
    if (arg_parser.isSet("about")) {
        ui->tabWidget->setCurrentIndex(1);
    }

    if (arg_parser.isSet("test")) {
        ui->labelLoginInfo->show();
        ui->buttonSetup->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Setup various items first time program runs
void MainWindow::setup()
{
    version = getVersion("mx-welcome");
    this->setWindowTitle(tr("MX Welcome"));

    QString old_conf_file = QDir::homePath() + "/.config/" + QApplication::applicationName() + ".conf";
    if (QFileInfo::exists(old_conf_file)) {
        QSettings old_settings(QApplication::applicationName());
        user_settings.setValue("AutoStartup", old_settings.value("AutoStartup", false).toBool());
        QFile::remove(old_conf_file);
    }
    bool autostart = user_settings.value("AutoStartup", false).toBool();
    ui->checkBox->setChecked(autostart);
    if (!autostart) {
        QFile::remove(QDir::homePath() + "/.config/autostart/mx-welcome.desktop");
    }

    // Setup title block & icons
    QSettings settings("/usr/share/mx-welcome/mx-welcome.conf", QSettings::NativeFormat);
    QSettings settingsusr("/etc/mx-welcome/mx-welcome.conf", QSettings::NativeFormat);
    QString DISTRO = settingsusr.value("DISTRO", settings.value("DISTRO").toString()).toString();
    QString CODENAME = settingsusr.value("CODENAME", settings.value("CODENAME").toString()).toString();
    QString HEADER = settingsusr.value("HEADER", settings.value("HEADER").toString()).toString();
    QString LOGO = settingsusr.value("LOGO", settings.value("LOGO").toString()).toString();
    QString SUPPORTED = settingsusr.value("SUPPORTED", settings.value("SUPPORTED").toString()).toString();
    TOSCMD = settingsusr.value("TOSCMD", settings.value("TOSCMD").toString()).toString();
    QString TOSTEXT = settingsusr.value("TOSTEXT", settings.value("TOSTEXT").toString()).toString();
    if (!TOSTEXT.isEmpty()) {
        ui->labelTOS->setText(TOSTEXT);
    }
    QString icons[11], texts[11];
    {
        auto cfg = [&](int idx, QString &cmd, QPushButton *btn) {
            auto const n = QString::number(idx);
            icons[idx - 1] = settingsusr.value(n + "icon", settings.value(n + "icon").toString()).toString();
            texts[idx - 1] = settingsusr.value(n + "text", settings.value(n + "text").toString()).toString();
            if (!texts[idx - 1].isEmpty())
                btn->setText(texts[idx - 1]);
            cmd = settingsusr.value(n + "command", settings.value(n + "command").toString()).toString();
        };
        cfg(1, SETUPCMD, ui->buttonSetup);
        cfg(2, FAQCMD, ui->buttonFAQ);
        cfg(3, FORUMCMD, ui->buttonForum);
        cfg(4, MANUALCMD, ui->buttonManual);
        cfg(5, VIDEOCMD, ui->buttonVideo);
        cfg(6, WIKICMD, ui->buttonWiki);
        cfg(7, CONTRIBUTECMD, ui->buttonContribute);
        cfg(8, TOOLSCMD, ui->buttonTools);
        cfg(9, PACKAGEINSTALLERCMD, ui->buttonPackageInstall);
        cfg(10, TWEAKCMD, ui->buttonPanelOrient);
        cfg(11, TOURCMD, ui->buttonTour);
    }

    // Hide tour if not present AND no configured text
    if (texts[10].isEmpty()) {
        if (!QFile::exists("/usr/bin/mx-tour")) {
            ui->buttonTour->hide();
        }
    }

    QString LIVEUSERINFOTEXT
        = settingsusr.value("LIVEUSERINFOTEXT", settings.value("LIVEUSERINFOTEXT").toString()).toString();
    if (!LIVEUSERINFOTEXT.isEmpty()) {
        ui->labelLoginInfo->setText(LIVEUSERINFOTEXT);
    }
    QString SHOWLIVEUSERINFO
        = settingsusr.value("SHOWLIVEUSERINFO", settings.value("SHOWLIVEUSERINFO", "true").toString()).toString();
    ui->labelLoginInfo->setText("<p align=\"center\">" + tr("User demo, password:") + "<b> demo</b>. "
                                + tr("Superuser root, password:") + "<b> root</b>." + "</p>");

    // If running live
    const QStringList dfLines = runCmd("df -T /").split('\n', Qt::SkipEmptyParts);
    const QString test = dfLines.isEmpty()
                             ? QString()
                             : dfLines.last().section(' ', 1, 1, QString::SectionSkipEmpty).trimmed();
    if (test == "aufs" || test == "overlay") {
        ui->checkBox->setVisible(false);
        ui->labelLoginInfo->setVisible(SHOWLIVEUSERINFO != "false");
    } else {
        ui->labelLoginInfo->setVisible(false);
        ui->buttonSetup->setVisible(false);
    }

    // Check /etc/lsb-release file, overridable
    QString CHECKLSB_RELEASE
        = settingsusr.value("CHECKLSB_RELEASE", settings.value("CHECKLSB_RELEASE", "true").toString()).toString();

    if (CHECKLSB_RELEASE != "false") {
        if (QFileInfo::exists("/etc/lsb-release")) {
            QSettings lsb("/etc/lsb-release", QSettings::NativeFormat);
            QString MAINDISTRO = lsb.value("DISTRIB_ID").toString();
            CODENAME = lsb.value("DISTRIB_CODENAME").toString();
            QString DISTRIB_RELEASE = lsb.value("DISTRIB_RELEASE").toString();
            DISTRO = MAINDISTRO + "-" + DISTRIB_RELEASE;
        }
    }

    QFile file("/etc/debian_version");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Errorinxi"), file.errorString());
    }

    QTextStream in(&file);
    debian_version = in.readLine();
    file.close();

    ui->LabelDebianVersion->setText(debian_version);

    ui->labelSupportUntil->setText(SUPPORTED);

    QString DESKTOPSTRING;
    for (const QString &line : runCmd("LANG=C.UTF-8 inxi -c 0 -S").split('\n', Qt::SkipEmptyParts)) {
        if (line.contains(QStringLiteral("Desktop"))) {
            DESKTOPSTRING = line;
            break;
        }
    }
    QRegularExpression re(R"(Desktop:\s*(.+?)\s+v:\s*([\d\.]+))");
    QRegularExpressionMatch match = re.match(DESKTOPSTRING);

    QString DESKTOP, ver;
    if (match.hasMatch()) {
        DESKTOP = match.captured(1);
        ver = match.captured(2);
        DESKTOP = match.captured(1) + " " + ver;
    }
    if (DESKTOP.contains("Fluxbox")) {
        isfluxbox = true;
        QFile file("/etc/mxfb_version");
        if (file.exists()) {
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(this, tr("Error"), file.errorString());
            }
            QTextStream in(&file);
            QString mxfluxbox_version = in.readLine();
            file.close();
            if (!mxfluxbox_version.isEmpty()) {
                DESKTOP.append(" " + mxfluxbox_version);
            }
        }
    }

    ui->labelDesktopVersion->setText(DESKTOP);

    ui->labelTitle->setText(
        tr(R"(<html><head/><body><p align="center"><span style=" font-size:14pt; font-weight:600;">%1 &quot;%2&quot;</span></p></body></html>)")
            .arg(DISTRO, CODENAME));
    if (QFile::exists(HEADER)) {
        ui->labelgraphic->setPixmap(HEADER);
    }

    // Setup icons
    ui->buttonSetup->setIcon(QIcon(icons[0]));
    ui->buttonFAQ->setIcon(QIcon(icons[1]));
    ui->buttonForum->setIcon(QIcon(icons[2]));
    ui->buttonManual->setIcon(QIcon(icons[3]));
    ui->buttonVideo->setIcon(QIcon(icons[4]));
    ui->buttonWiki->setIcon(QIcon(icons[5]));
    ui->buttonContribute->setIcon(QIcon(icons[6]));
    ui->buttonTools->setIcon(QIcon(icons[7]));
    ui->buttonPackageInstall->setIcon(QIcon(icons[8]));
    ui->buttonPanelOrient->setIcon(QIcon(icons[9]));
    ui->buttonTour->setIcon(QIcon(icons[10]));
    ui->labelMX->setPixmap(QPixmap(LOGO));

    // Setup about labels
    ui->labelMXversion->setText(DISTRO);

    setTabStyle();
    this->adjustSize();
}

// Util function for getting bash command output and error code
QString MainWindow::runCmd(const QString& cmd)
{
    QEventLoop loop;
    QProcess proc;
    proc.setProcessChannelMode(QProcess::MergedChannels);
    QTimer::singleShot(10000, &loop, [&proc, &loop]() {
        if (proc.state() != QProcess::NotRunning)
            proc.kill();
        loop.quit();
    });
    connect(&proc, &QProcess::finished, &loop, &QEventLoop::quit);
    proc.start("/bin/bash", {"-c", cmd});
    loop.exec();
    return QString::fromUtf8(proc.readAll().trimmed());
}

// Get version of the program
QString MainWindow::getVersion(const QString& name)
{
    return runCmd("dpkg-query -f '${Version}' -W " + name);
}

void MainWindow::on_buttonAbout_clicked()
{
    this->hide();
    displayAboutMsgBox(
        tr("About MX Welcome"),
        "<p align=\"center\"><b><h2>" + tr("MX Welcome") + "</h2></b></p><p align=\"center\">" + tr("Version: ")
            + version + "</p><p align=\"center\"><h3>" + tr("Program for displaying a welcome screen in MX Linux")
            + "</h3></p><p align=\"center\"><a href=\"http://mxlinux.org\">http://mxlinux.org</a><br /></p>"
              "<p align=\"center\">"
            + tr("Copyright (c) MX Linux") + "<br /><br /></p>",
        "/usr/share/doc/mx-welcome/license.html", tr("%1 License").arg(this->windowTitle()));
    this->show();
}

// Add/remove autostart at login
void MainWindow::on_checkBox_clicked(bool checked)
{
    user_settings.setValue("AutoStartup", checked);
    if (checked) {
        QFile::copy("/usr/share/mx-welcome/mx-welcome.desktop",
                    QDir::homePath() + "/.config/autostart/mx-welcome.desktop");
    } else {
        QFile::remove(QDir::homePath() + "/.config/autostart/mx-welcome.desktop");
    }
}

// Start MX-Tools
void MainWindow::on_buttonTools_clicked() const
{
    QString cmd = TOOLSCMD.isEmpty() ? "mx-tools" : TOOLSCMD;
    QProcess::startDetached("/bin/sh", {"-c", cmd});
}

// Launch Manual in browser
void MainWindow::on_buttonManual_clicked() const
{
    QString cmd = isfluxbox ? "mxfb-help" : "mx-manual";
    if (!MANUALCMD.isEmpty()) {
        cmd = MANUALCMD;
    }
    QProcess::startDetached("/bin/sh", {"-c", cmd});
}

// Launch Forum in browser
void MainWindow::on_buttonForum_clicked() const
{
    if (FORUMCMD.isEmpty()) {
        openUrl(QStringLiteral("http://forum.mxlinux.org/index.php"));
        return;
    }
    QProcess::startDetached("/bin/sh", {"-c", FORUMCMD});
}

// Launch Wiki in browser
void MainWindow::on_buttonWiki_clicked() const
{
    if (WIKICMD.isEmpty()) {
        openUrl(QStringLiteral("http://www.mxlinux.org/wiki"));
        return;
    }
    QProcess::startDetached("/bin/sh", {"-c", WIKICMD});
}

// Launch Video links in browser
void MainWindow::on_buttonVideo_clicked() const
{
    if (VIDEOCMD.isEmpty()) {
        openUrl(QStringLiteral("http://www.mxlinux.org/videos/"));
        return;
    }
    QProcess::startDetached("/bin/sh", {"-c", VIDEOCMD});
}

// Launch Contribution page
void MainWindow::on_buttonContribute_clicked() const
{
    if (CONTRIBUTECMD.isEmpty()) {
        openUrl(QStringLiteral("http://www.mxlinux.org/donate"));
        return;
    }
    QProcess::startDetached("/bin/sh", {"-c", CONTRIBUTECMD});
}

void MainWindow::on_buttonPanelOrient_clicked() const
{
    QString cmd = TWEAKCMD.isEmpty() ? "mx-tweak" : TWEAKCMD;
    QProcess::startDetached("/bin/sh", {"-c", cmd});
}

void MainWindow::on_buttonPackageInstall_clicked() const
{
    QString cmd = PACKAGEINSTALLERCMD.isEmpty() ? "mx-packageinstaller" : PACKAGEINSTALLERCMD;
    QProcess::startDetached("/bin/sh", {"-c", cmd});
}

void MainWindow::on_buttonFAQ_clicked() const
{
    QString cmd = FAQCMD.isEmpty() ? "mx-faq" : FAQCMD;
    QProcess::startDetached("/bin/sh", {"-c", cmd});
}

void MainWindow::on_buttonSetup_clicked() const
{
    QString cmd = SETUPCMD.isEmpty() ? "minstall-launcher" : SETUPCMD;
    QProcess::startDetached("/bin/sh", {"-c", cmd});
}

void MainWindow::on_buttonTOS_clicked() const
{
    if (TOSCMD.isEmpty()) {
        termsofuse();
    } else {
        QProcess::startDetached("/bin/sh", {"-c", TOSCMD});
    }
}

void MainWindow::on_ButtonQSI_clicked() const
{
    if (debian_version.section(".", 0, 0) == "10") {
        QProcess::startDetached("/bin/sh", {"-c", "x-terminal-emulator -e bash -c \"/usr/bin/quick-system-info-mx\""});
    } else {
        QProcess::startDetached("/usr/bin/quick-system-info-gui");
    }
}

void MainWindow::shortSystemInfo()
{
    ui->textBrowser->setText(runCmd("LANG=C inxi -c 0"));
}
void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 1) {
        shortSystemInfo();
    }
    setTabStyle();
}

void MainWindow::resizeEvent(QResizeEvent* /*unused*/)
{
    setTabStyle();
}

void MainWindow::setTabStyle()
{
    QString tw = QString::number(ui->tabWidget->width() / 2 - 1);
    ui->tabWidget->setStyleSheet(""
                                 "QTabBar::tab:!selected{width: "
                                 + tw
                                 + "px; background:  rgba(140, 135, 135, 50)}"
                                   ""
                                   "QTabBar::tab:selected{width: "
                                 + tw
                                 + "px}"
                                   "");
}

void MainWindow::on_buttonTour_clicked() const
{
    QString cmd = TOURCMD.isEmpty() ? "mx-tour" : TOURCMD;
    QProcess::startDetached("/bin/sh", {"-c", cmd});
}

void MainWindow::termsofuse() const
{
    const auto width = 600;
    const auto height = 500;

    auto* TOS = new QDialog;
    TOS->setWindowTitle(QObject::tr("Terms of Use"));
    TOS->resize(width, height);

    auto* text = new QTextEdit(TOS);
    text->setReadOnly(true);
    QProcess proc;
    proc.start("zless", {"/usr/share/mx-welcome/TOS"}, QIODevice::ReadOnly);
    proc.waitForFinished();
    text->setText(proc.readAllStandardOutput());

    auto* btnClose = new QPushButton(QObject::tr("&Close"), TOS);
    btnClose->setIcon(QIcon::fromTheme("window-close"));
    QObject::connect(btnClose, &QPushButton::clicked, TOS, &QDialog::close);

    auto* layout = new QVBoxLayout(TOS);
    layout->addWidget(text);
    layout->addWidget(btnClose);
    TOS->setLayout(layout);
    TOS->exec();
}
