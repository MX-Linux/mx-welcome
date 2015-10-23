/**********************************************************************
 *  mxwelcome.h
 **********************************************************************
 * Copyright (C) 2015 MX Authors
 *
 * Authors: Adrian
 *          Paul David Callahan
 *          MX & MEPIS Community <http://forum.mepiscommunity.org>
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


#ifndef MXWELCOME_H
#define MXWELCOME_H

#include <QMessageBox>
#include <QProcess>

namespace Ui {
class mxwelcome;
}

struct Result {
    int exitCode;
    QString output;
};


class mxwelcome : public QDialog
{
    Q_OBJECT

protected:
    QProcess *proc;

public:
    explicit mxwelcome(QWidget *parent = 0);
    ~mxwelcome();

    Result runCmd(QString cmd);
    QString getVersion(QString name);

    QString version;
    QString output;

    void setup();

public slots:
    void setConnections();    
    void disconnectAll();

private slots:
    void on_buttonAbout_clicked();
    void on_checkBox_clicked(bool checked);
    void on_buttonTools_clicked();
    void on_buttonManual_clicked();
    void on_buttonForum_clicked();
    void on_buttonWiki_clicked();
    void on_buttonVideo_clicked();
    void on_buttonContribute_clicked();
    void on_buttonLogininfo_clicked();

private:
    Ui::mxwelcome *ui;
};


#endif // MXSNAPSHOT_H

