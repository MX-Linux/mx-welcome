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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mxwelcome
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *selectionPage;
    QGridLayout *gridLayout_2;
    QWidget *outputPage;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *outputBox;
    QLabel *outputLabel;
    QProgressBar *progressBar;
    QGridLayout *buttonBar;
    QSpacerItem *horizontalSpacer2;
    QPushButton *buttonAbout;
    QSpacerItem *horizontalSpacer1;
    QPushButton *buttonCancel;
    QLabel *labelMX;

    void setupUi(QDialog *mxwelcome)
    {
        if (mxwelcome->objectName().isEmpty())
            mxwelcome->setObjectName(QStringLiteral("mxwelcome"));
        mxwelcome->resize(779, 505);
        verticalLayout = new QVBoxLayout(mxwelcome);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(mxwelcome);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        selectionPage = new QWidget();
        selectionPage->setObjectName(QStringLiteral("selectionPage"));
        gridLayout_2 = new QGridLayout(selectionPage);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        stackedWidget->addWidget(selectionPage);
        outputPage = new QWidget();
        outputPage->setObjectName(QStringLiteral("outputPage"));
        verticalLayout_2 = new QVBoxLayout(outputPage);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        outputBox = new QTextBrowser(outputPage);
        outputBox->setObjectName(QStringLiteral("outputBox"));

        verticalLayout_2->addWidget(outputBox);

        outputLabel = new QLabel(outputPage);
        outputLabel->setObjectName(QStringLiteral("outputLabel"));
        outputLabel->setWordWrap(true);

        verticalLayout_2->addWidget(outputLabel);

        progressBar = new QProgressBar(outputPage);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        verticalLayout_2->addWidget(progressBar);

        stackedWidget->addWidget(outputPage);

        verticalLayout->addWidget(stackedWidget);

        buttonBar = new QGridLayout();
        buttonBar->setSpacing(5);
        buttonBar->setObjectName(QStringLiteral("buttonBar"));
        buttonBar->setSizeConstraint(QLayout::SetDefaultConstraint);
        buttonBar->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer2 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonBar->addItem(horizontalSpacer2, 0, 4, 1, 1);

        buttonAbout = new QPushButton(mxwelcome);
        buttonAbout->setObjectName(QStringLiteral("buttonAbout"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonAbout->sizePolicy().hasHeightForWidth());
        buttonAbout->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/accessories-text-editor.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAbout->setIcon(icon);
        buttonAbout->setAutoDefault(true);

        buttonBar->addWidget(buttonAbout, 0, 0, 1, 1);

        horizontalSpacer1 = new QSpacerItem(183, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonBar->addItem(horizontalSpacer1, 0, 1, 1, 1);

        buttonCancel = new QPushButton(mxwelcome);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../../../../../usr/share/mx-welcome/icons/gtk-cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonCancel->setIcon(icon1);
        buttonCancel->setAutoDefault(true);

        buttonBar->addWidget(buttonCancel, 0, 7, 1, 1);

        labelMX = new QLabel(mxwelcome);
        labelMX->setObjectName(QStringLiteral("labelMX"));
        labelMX->setMaximumSize(QSize(32, 32));
        labelMX->setMidLineWidth(0);
        labelMX->setPixmap(QPixmap(QString::fromUtf8("../../../../../../../usr/share/mx-welcome/icons/mxfcelogo.png")));
        labelMX->setScaledContents(true);

        buttonBar->addWidget(labelMX, 0, 2, 1, 1);


        verticalLayout->addLayout(buttonBar);


        retranslateUi(mxwelcome);
        QObject::connect(buttonCancel, SIGNAL(pressed()), mxwelcome, SLOT(close()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mxwelcome);
    } // setupUi

    void retranslateUi(QDialog *mxwelcome)
    {
        mxwelcome->setWindowTitle(QApplication::translate("mxwelcome", "MX Welcome", 0));
        outputLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        buttonAbout->setToolTip(QApplication::translate("mxwelcome", "About this application", 0));
#endif // QT_NO_TOOLTIP
        buttonAbout->setText(QApplication::translate("mxwelcome", "About...", 0));
        buttonAbout->setShortcut(QApplication::translate("mxwelcome", "Alt+B", 0));
#ifndef QT_NO_TOOLTIP
        buttonCancel->setToolTip(QApplication::translate("mxwelcome", "Quit application", 0));
#endif // QT_NO_TOOLTIP
        buttonCancel->setText(QApplication::translate("mxwelcome", "Close", 0));
        buttonCancel->setShortcut(QApplication::translate("mxwelcome", "Alt+N", 0));
        labelMX->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mxwelcome: public Ui_mxwelcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MXWELCOME_H
