/********************************************************************************
** Form generated from reading UI file 'mxwelcome.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MXWELCOME_H
#define UI_MXWELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include "flatbutton.h"

QT_BEGIN_NAMESPACE

class Ui_mxwelcome
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *labelTitle;
    QLabel *labelIntro;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_7;
    FlatButton *buttonManual;
    QSpacerItem *horizontalSpacer_8;
    FlatButton *buttonForum;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_3;
    FlatButton *buttonWiki;
    QSpacerItem *horizontalSpacer_5;
    FlatButton *buttonVideo;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    FlatButton *buttonTools;
    QSpacerItem *horizontalSpacer_10;
    FlatButton *buttonContribute;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_13;
    FlatButton *buttonPanelOrient;
    FlatButton *buttonPackageInstall;
    QGridLayout *buttonBar;
    QPushButton *buttonCancel;
    QLabel *labelMX;
    QPushButton *buttonAbout;
    QSpacerItem *horizontalSpacer2;
    QSpacerItem *horizontalSpacer1;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_11;
    FlatButton *buttonLogininfo;
    QCheckBox *checkBox;

    void setupUi(QDialog *mxwelcome)
    {
        if (mxwelcome->objectName().isEmpty())
            mxwelcome->setObjectName(QStringLiteral("mxwelcome"));
        mxwelcome->resize(674, 428);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../../../usr/share/pixmaps/mx/mx-welcome.png"), QSize(), QIcon::Normal, QIcon::Off);
        mxwelcome->setWindowIcon(icon);
        mxwelcome->setSizeGripEnabled(false);
        mxwelcome->setModal(false);
        gridLayout = new QGridLayout(mxwelcome);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(mxwelcome);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(654, 0));
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 3, 1, 1);

        labelTitle = new QLabel(frame);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelTitle, 1, 3, 1, 1);

        labelIntro = new QLabel(frame);
        labelIntro->setObjectName(QStringLiteral("labelIntro"));
        labelIntro->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelIntro->setWordWrap(true);

        gridLayout_2->addWidget(labelIntro, 2, 0, 1, 6);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 3, 1, 1);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 4, 0, 1, 6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 5, 0, 1, 1);

        buttonManual = new FlatButton(frame);
        buttonManual->setObjectName(QStringLiteral("buttonManual"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonManual->sizePolicy().hasHeightForWidth());
        buttonManual->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/users-manual.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonManual->setIcon(icon1);
        buttonManual->setIconSize(QSize(42, 42));
        buttonManual->setAutoDefault(false);
        buttonManual->setFlat(true);

        gridLayout_2->addWidget(buttonManual, 5, 1, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 5, 3, 1, 1);

        buttonForum = new FlatButton(frame);
        buttonForum->setObjectName(QStringLiteral("buttonForum"));
        sizePolicy.setHeightForWidth(buttonForum->sizePolicy().hasHeightForWidth());
        buttonForum->setSizePolicy(sizePolicy);
        buttonForum->setMinimumSize(QSize(141, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/forums.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonForum->setIcon(icon2);
        buttonForum->setIconSize(QSize(42, 42));
        buttonForum->setAutoDefault(false);
        buttonForum->setFlat(true);

        gridLayout_2->addWidget(buttonForum, 5, 4, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 5, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 6, 0, 1, 1);

        buttonWiki = new FlatButton(frame);
        buttonWiki->setObjectName(QStringLiteral("buttonWiki"));
        sizePolicy.setHeightForWidth(buttonWiki->sizePolicy().hasHeightForWidth());
        buttonWiki->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/wiki.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonWiki->setIcon(icon3);
        buttonWiki->setIconSize(QSize(42, 42));
        buttonWiki->setAutoDefault(false);
        buttonWiki->setFlat(true);

        gridLayout_2->addWidget(buttonWiki, 6, 1, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 6, 3, 1, 1);

        buttonVideo = new FlatButton(frame);
        buttonVideo->setObjectName(QStringLiteral("buttonVideo"));
        sizePolicy.setHeightForWidth(buttonVideo->sizePolicy().hasHeightForWidth());
        buttonVideo->setSizePolicy(sizePolicy);
        buttonVideo->setMinimumSize(QSize(141, 0));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/videos.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonVideo->setIcon(icon4);
        buttonVideo->setIconSize(QSize(42, 42));
        buttonVideo->setAutoDefault(false);
        buttonVideo->setFlat(true);

        gridLayout_2->addWidget(buttonVideo, 6, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 6, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 7, 0, 1, 1);

        buttonTools = new FlatButton(frame);
        buttonTools->setObjectName(QStringLiteral("buttonTools"));
        buttonTools->setMinimumSize(QSize(0, 0));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonTools->setIcon(icon5);
        buttonTools->setIconSize(QSize(42, 42));
        buttonTools->setAutoDefault(false);
        buttonTools->setFlat(true);

        gridLayout_2->addWidget(buttonTools, 7, 1, 2, 2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 7, 3, 1, 1);

        buttonContribute = new FlatButton(frame);
        buttonContribute->setObjectName(QStringLiteral("buttonContribute"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/contribute.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonContribute->setIcon(icon6);
        buttonContribute->setIconSize(QSize(42, 42));
        buttonContribute->setFlat(true);

        gridLayout_2->addWidget(buttonContribute, 7, 4, 2, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 7, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(59, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 8, 0, 2, 1);

        horizontalSpacer_12 = new QSpacerItem(142, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_12, 8, 2, 2, 2);

        horizontalSpacer_13 = new QSpacerItem(59, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_13, 8, 5, 2, 1);

        buttonPanelOrient = new FlatButton(frame);
        buttonPanelOrient->setObjectName(QStringLiteral("buttonPanelOrient"));
        buttonPanelOrient->setMinimumSize(QSize(0, 0));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../../../usr/share/mx-welcome/icons/mxwelcome-icon-panel-orient.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPanelOrient->setIcon(icon7);
        buttonPanelOrient->setIconSize(QSize(42, 42));
        buttonPanelOrient->setAutoDefault(false);
        buttonPanelOrient->setFlat(true);

        gridLayout_2->addWidget(buttonPanelOrient, 9, 1, 1, 1);

        buttonPackageInstall = new FlatButton(frame);
        buttonPackageInstall->setObjectName(QStringLiteral("buttonPackageInstall"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("../../../usr/share/mx-welcome/icons/mxwelcome-icon-packageinstaller.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPackageInstall->setIcon(icon8);
        buttonPackageInstall->setIconSize(QSize(42, 42));
        buttonPackageInstall->setFlat(true);

        gridLayout_2->addWidget(buttonPackageInstall, 9, 4, 1, 1);

        labelTitle->raise();
        buttonManual->raise();
        labelIntro->raise();
        buttonForum->raise();
        buttonVideo->raise();
        buttonWiki->raise();
        line_3->raise();
        buttonTools->raise();
        buttonContribute->raise();
        buttonPackageInstall->raise();
        buttonPanelOrient->raise();

        gridLayout->addWidget(frame, 0, 0, 1, 5);

        buttonBar = new QGridLayout();
        buttonBar->setSpacing(5);
        buttonBar->setObjectName(QStringLiteral("buttonBar"));
        buttonBar->setSizeConstraint(QLayout::SetDefaultConstraint);
        buttonBar->setContentsMargins(0, 0, 0, 0);
        buttonCancel = new QPushButton(mxwelcome);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy1);
        QIcon icon9;
        icon9.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/gtk-cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCancel->setIcon(icon9);
        buttonCancel->setAutoDefault(true);

        buttonBar->addWidget(buttonCancel, 0, 8, 1, 1);

        labelMX = new QLabel(mxwelcome);
        labelMX->setObjectName(QStringLiteral("labelMX"));
        labelMX->setMaximumSize(QSize(32, 32));
        labelMX->setMidLineWidth(0);
        labelMX->setPixmap(QPixmap(QString::fromUtf8("../../../../../../../usr/share/mx-welcome/icons/mxfcelogo.png")));
        labelMX->setScaledContents(true);

        buttonBar->addWidget(labelMX, 0, 3, 1, 1);

        buttonAbout = new QPushButton(mxwelcome);
        buttonAbout->setObjectName(QStringLiteral("buttonAbout"));
        sizePolicy1.setHeightForWidth(buttonAbout->sizePolicy().hasHeightForWidth());
        buttonAbout->setSizePolicy(sizePolicy1);
        QIcon icon10;
        icon10.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/accessories-text-editor.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAbout->setIcon(icon10);
        buttonAbout->setAutoDefault(true);
        buttonAbout->setDefault(true);

        buttonBar->addWidget(buttonAbout, 0, 0, 1, 1);

        horizontalSpacer2 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonBar->addItem(horizontalSpacer2, 0, 5, 1, 1);

        horizontalSpacer1 = new QSpacerItem(183, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonBar->addItem(horizontalSpacer1, 0, 1, 1, 1);


        gridLayout->addLayout(buttonBar, 4, 0, 1, 4);

        line_2 = new QFrame(mxwelcome);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 5);

        horizontalSpacer_11 = new QSpacerItem(161, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 1, 1, 2, 2);

        buttonLogininfo = new FlatButton(mxwelcome);
        buttonLogininfo->setObjectName(QStringLiteral("buttonLogininfo"));
        sizePolicy.setHeightForWidth(buttonLogininfo->sizePolicy().hasHeightForWidth());
        buttonLogininfo->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        buttonLogininfo->setFont(font);
        buttonLogininfo->setAutoFillBackground(false);
        QIcon icon11;
        icon11.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/zoom-fit.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLogininfo->setIcon(icon11);
        buttonLogininfo->setAutoDefault(false);
        buttonLogininfo->setFlat(true);

        gridLayout->addWidget(buttonLogininfo, 1, 0, 2, 1);

        checkBox = new QCheckBox(mxwelcome);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 2, 3, 1, 2);


        retranslateUi(mxwelcome);
        QObject::connect(buttonCancel, SIGNAL(pressed()), mxwelcome, SLOT(close()));

        QMetaObject::connectSlotsByName(mxwelcome);
    } // setupUi

    void retranslateUi(QDialog *mxwelcome)
    {
        mxwelcome->setWindowTitle(QApplication::translate("mxwelcome", "MX Welcome", 0));
        labelTitle->setText(QApplication::translate("mxwelcome", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">MX-15 </span><span style=\" font-size:14pt; font-weight:600; color:#000000;\">&quot;Fusion&quot;</span></p></body></html>", 0));
        labelIntro->setText(QApplication::translate("mxwelcome", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Welcome to MX Linux, a fast, friendly, and stable OS loaded with amazing tools and supported by a great community. </span></p></body></html>", 0));
        buttonManual->setText(QApplication::translate("mxwelcome", "Users Manual", 0));
        buttonForum->setText(QApplication::translate("mxwelcome", "Forums", 0));
        buttonWiki->setText(QApplication::translate("mxwelcome", "Wiki", 0));
        buttonVideo->setText(QApplication::translate("mxwelcome", "Videos", 0));
        buttonTools->setText(QApplication::translate("mxwelcome", "Tools", 0));
        buttonContribute->setText(QApplication::translate("mxwelcome", "Contribute", 0));
        buttonPanelOrient->setText(QApplication::translate("mxwelcome", "Panel Orientation", 0));
        buttonPackageInstall->setText(QApplication::translate("mxwelcome", "Popular Apps", 0));
#ifndef QT_NO_TOOLTIP
        buttonCancel->setToolTip(QApplication::translate("mxwelcome", "Quit application", 0));
#endif // QT_NO_TOOLTIP
        buttonCancel->setText(QApplication::translate("mxwelcome", "Close", 0));
        buttonCancel->setShortcut(QApplication::translate("mxwelcome", "Alt+N", 0));
        labelMX->setText(QString());
#ifndef QT_NO_TOOLTIP
        buttonAbout->setToolTip(QApplication::translate("mxwelcome", "About this application", 0));
#endif // QT_NO_TOOLTIP
        buttonAbout->setText(QApplication::translate("mxwelcome", "About...", 0));
        buttonAbout->setShortcut(QApplication::translate("mxwelcome", "Alt+B", 0));
        buttonLogininfo->setText(QApplication::translate("mxwelcome", "Login Info", 0));
        checkBox->setText(QApplication::translate("mxwelcome", "Show this dialog at start up", 0));
    } // retranslateUi

};

namespace Ui {
    class mxwelcome: public Ui_mxwelcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MXWELCOME_H
