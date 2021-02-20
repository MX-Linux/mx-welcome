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


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "flatbutton.h"
#include "version.h"

#include <QFileInfo>
#include <QTextEdit>
#include <QDebug>
#include <QSettings>


MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    qDebug().noquote() << QCoreApplication::applicationName() << "version:" << VERSION;
    ui->setupUi(this);
    setWindowFlags(Qt::Window); // for the close, min and max buttons
    setup();
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

    QSettings user_settings(QCoreApplication::applicationName());
    bool autostart = user_settings.value("AutoStartup", false).toBool();
    ui->checkBox->setChecked(autostart);
    if (!autostart) system("rm ~/.config/autostart/mx-welcome.desktop >/dev/null 2>&1");

    ui->labelLoginInfo->setText("<p align=\"center\">" + tr("User demo, password:") + "<b> demo</b>. " + tr("Superuser root, password:") + "<b> root</b>." + "</p>");
    // if running live
    QString test = runCmd("df -T / |tail -n1 |awk '{print $2}'").output;
    ( test == "aufs" || test == "overlay" ) ? ui->checkBox->hide() : ui->labelLoginInfo->hide();

    // setup title block & icons
    QSettings settings("/usr/share/mx-welcome/mx-welcome.conf", QSettings::NativeFormat);
    QString DISTRO=settings.value("DISTRO").toString();
    QString CODENAME=settings.value("CODENAME").toString();
    QString CONTRIBUTE=settings.value("CONTRIBUTE").toString();
    QString CODECS=settings.value("CODECS").toString();
    QString FAQ=settings.value("FAQ").toString();
    QString FORUMS=settings.value("FORUMS").toString();
    QString LOGO=settings.value("LOGO").toString();
    QString PACKAGEINSTALLER=settings.value("PACKAGEINSTALLER").toString();
    QString PANELORIENT=settings.value("PANELORIENT").toString();
    QString TOOLS=settings.value("TOOLS").toString();
    QString MANUAL=settings.value("MANUAL").toString();
    QString VIDEOS=settings.value("VIDEOS").toString();
    QString WIKI=settings.value("WIKI").toString();

    ui->labelTitle->setText(tr("<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">%1 &quot;%2&quot;</span></p></body></html>").arg(DISTRO).arg(CODENAME));

    //setup icons
    ui->buttonCodecs->setIcon(QIcon(CODECS));
    ui->buttonContribute->setIcon(QIcon(CONTRIBUTE));
    ui->buttonFAQ->setIcon(QIcon(FAQ));
    ui->buttonForum->setIcon(QIcon(FORUMS));
    ui->labelMX->setPixmap(QPixmap(LOGO));
    ui->buttonPackageInstall->setIcon(QIcon(PACKAGEINSTALLER));
    ui->buttonPanelOrient->setIcon(QIcon(PANELORIENT));
    ui->buttonTools->setIcon(QIcon(TOOLS));
    ui->buttonManual->setIcon(QIcon(MANUAL));
    ui->buttonVideo->setIcon(QIcon(VIDEOS));
    ui->buttonWiki->setIcon(QIcon(WIKI));

    this->adjustSize();
}

// Util function for getting bash command output and error code
Result MainWindow::runCmd(QString cmd)
{
    QEventLoop loop;
    proc = new QProcess(this);
    proc->setReadChannelMode(QProcess::MergedChannels);
    connect(proc, static_cast<void (QProcess::*)(int)>(&QProcess::finished), &loop, &QEventLoop::quit);
    proc->start("/bin/bash", QStringList() << "-c" << cmd);
    loop.exec();
    Result result = {proc->exitCode(), proc->readAll().trimmed()};
    delete proc;
    return result;
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
                       tr("About MX Welcome"), "<p align=\"center\"><b><h2>" +
                       tr("MX Welcome") + "</h2></b></p><p align=\"center\">" + tr("Version: ") + version + "</p><p align=\"center\"><h3>" +
                       tr("Program for displaying a welcome screen in MX Linux") +
                       "</h3></p><p align=\"center\"><a href=\"http://www.mxlinux.org/mx\">http://www.mxlinux.org/mx</a><br /></p><p align=\"center\">" +
                       tr("Copyright (c) MX Linux") + "<br /><br /></p>", 0, this);
    QPushButton *btnLicense = msgBox.addButton(tr("License"), QMessageBox::HelpRole);
    QPushButton *btnChangelog = msgBox.addButton(tr("Changelog"), QMessageBox::HelpRole);
    QPushButton *btnCancel = msgBox.addButton(tr("Cancel"), QMessageBox::NoRole);
    btnCancel->setIcon(QIcon::fromTheme("window-close"));

    msgBox.exec();

    if (msgBox.clickedButton() == btnLicense) {
        QString cmd = QString("mx-viewer file:///usr/share/doc/mx-welcome/license.html '%1'").arg(tr("MX Welcome"));
        system(cmd.toUtf8());
    } else if (msgBox.clickedButton() == btnChangelog) {
        QDialog *changelog = new QDialog(this);
        changelog->resize(600, 500);

        QTextEdit *text = new QTextEdit;
        text->setReadOnly(true);
        text->setText(runCmd("zless /usr/share/doc/" + QFileInfo(QCoreApplication::applicationFilePath()).fileName()  + "/changelog.gz").output);

        QPushButton *btnClose = new QPushButton(tr("&Close"));
        btnClose->setIcon(QIcon::fromTheme("window-close"));
        connect(btnClose, &QPushButton::clicked, changelog, &QDialog::close);

        QVBoxLayout *layout = new QVBoxLayout;
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
    QSettings user_settings(QCoreApplication::applicationName());
    if (checked) {
        system("cp /usr/share/mx-welcome/mx-welcome.desktop ~/.config/autostart/mx-welcome.desktop");
        user_settings.setValue("AutoStartup", true);
    } else {
        system("rm ~/.config/autostart/mx-welcome.desktop >/dev/null 2>&1");
        user_settings.setValue("AutoStartup", false);
    }
}

// Start MX-Tools
void MainWindow::on_buttonTools_clicked()
{
    system("mx-tools&");
}

// Launch Manual in browser
void MainWindow::on_buttonManual_clicked()
{
    system("mx-manual&");
}

// Launch Forum in browser
void MainWindow::on_buttonForum_clicked()
{
    system("xdg-open http://forum.mxlinux.org/index.php");
}

// Launch Wiki in browser
void MainWindow::on_buttonWiki_clicked()
{
    system("xdg-open http://www.mxlinux.org/wiki");
}

// Launch Video links in browser
void MainWindow::on_buttonVideo_clicked()
{
    system("xdg-open http://www.mxlinux.org/videos/");
}

// Launch Contribution page
void MainWindow::on_buttonContribute_clicked()
{
    system("xdg-open http://www.mxlinux.org/donate");
}

void MainWindow::on_buttonPanelOrient_clicked()
{
    system("mx-tweak&");
}

void MainWindow::on_buttonPackageInstall_clicked()
{
    system("su-to-root -X -c mx-packageinstaller&");
}

void MainWindow::on_buttonCodecs_clicked()
{
    system("su-to-root -X -c mx-codecs&");
}

void MainWindow::on_buttonFAQ_clicked()
{
    system("mx-faq&");
}
