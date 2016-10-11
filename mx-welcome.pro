# **********************************************************************
# * Copyright (C) 2015 MX Authors
# *
# * Authors: Adrian
# *          Paul David Callahan
# *          MX Community <http://forum.mxlinux.org>
# *
# * This file is part of mx-welcome.
# *
# * mx-welcome is free software: you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation, either version 3 of the License, or
# * (at your option) any later version.
# *
# * mx-welcome is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
# *
# * You should have received a copy of the GNU General Public License
# * along with mx-welcome.  If not, see <http://www.gnu.org/licenses/>.
# **********************************************************************/

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mx-welcome
TEMPLATE = app


SOURCES += main.cpp\
        mxwelcome.cpp \
    flatbutton.cpp

HEADERS  += mxwelcome.h \
    flatbutton.h

FORMS    += mxwelcome.ui

TRANSLATIONS += translations/mx-welcome_ca.ts \
                translations/mx-welcome_de.ts \
                translations/mx-welcome_el.ts \
                translations/mx-welcome_es.ts \
                translations/mx-welcome_fr.ts \
                translations/mx-welcome_it.ts \
                translations/mx-welcome_ja.ts \
                translations/mx-welcome_nl.ts \
                translations/mx-welcome_pl.ts \
                translations/mx-welcome_ru.ts \
                translations/mx-welcome_sv.ts


