/**********************************************************************
 * Copyright (C) 2015-2026 MX Authors
 *
 * This file is part of mx-welcome and is distributed under GPL-3.0-or-later.
 **********************************************************************/

#include "backend.h"
#include "version.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QIcon>
#include <QLibraryInfo>
#include <QLocale>
#include <QMessageBox>
#include <QQmlApplicationEngine>
#include <QQuickImageProvider>
#include <QTranslator>

#include <cstdlib>
#include <unistd.h>

class ThemeIconProvider final : public QQuickImageProvider
{
public:
    ThemeIconProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override
    {
        const QSize target = requestedSize.isValid() ? requestedSize : QSize(64, 64);
        const QIcon fallback(QStringLiteral(":/qt/qml/MxWelcome/icons/mx-welcome.svg"));
        const QPixmap pixmap = QIcon::fromTheme(id, fallback).pixmap(target);
        if (size) {
            *size = pixmap.size();
        }
        return pixmap;
    }
};

int main(int argc, char *argv[])
{
    QApplication::setOrganizationName(QStringLiteral("MX-Linux"));
    QApplication::setApplicationName(QStringLiteral("mx-welcome"));
    QApplication::setApplicationDisplayName(QStringLiteral("MX Welcome"));
    QApplication::setApplicationVersion(QStringLiteral(VERSION));

    QApplication app(argc, argv);
    QApplication::setWindowIcon(QIcon::fromTheme(QStringLiteral("mx-welcome"),
                                                 QIcon(QStringLiteral(":/qt/qml/MxWelcome/icons/mx-welcome.svg"))));

    QCommandLineParser parser;
    parser.setApplicationDescription(QObject::tr("This tool displays the MX Linux welcome screen."));
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption({{"a", "about"},
                      QObject::tr("Start with About selected. The About page provides basic information about the "
                                  "current MX Linux version, the user's hardware, and access to a full system report.")});
    parser.addOption({{"t", "test"}, QObject::tr("Run a test mode.")});
    parser.process(app);

    QTranslator qtTranslator;
    if (qtTranslator.load(QStringLiteral("qt_") + QLocale().name(),
                          QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
        QApplication::installTranslator(&qtTranslator);
    }
    QTranslator qtBaseTranslator;
    if (qtBaseTranslator.load(QStringLiteral("qtbase_") + QLocale::system().name(),
                              QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
        QApplication::installTranslator(&qtBaseTranslator);
    }
    QTranslator appTranslator;
    if (appTranslator.load(QApplication::applicationName() + QLatin1Char('_') + QLocale::system().name(),
                           QStringLiteral("/usr/share/mx-welcome/locale"))) {
        QApplication::installTranslator(&appTranslator);
    }

    if (getuid() == 0) {
        QApplication::beep();
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("You must run this program as normal user."));
        return EXIT_FAILURE;
    }

    Backend backend(parser);
    QQmlApplicationEngine engine;
    engine.addImageProvider(QStringLiteral("icons"), new ThemeIconProvider);
    engine.setInitialProperties({{QStringLiteral("backend"), QVariant::fromValue(&backend)}});
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &app,
                     [] { QCoreApplication::exit(EXIT_FAILURE); }, Qt::QueuedConnection);
    engine.loadFromModule(QStringLiteral("MxWelcome"), QStringLiteral("Main"));

    return QApplication::exec();
}
