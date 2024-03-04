# **********************************************************************
# * Copyright (C) 2015-2024 MX Authors
# *
# * Authors: Adrian
# *          Paul David Callahan
# *          MX & MEPIS Community <http://forum.mepiscommunity.org>
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

QT       += core gui widgets
CONFIG   += c++1z

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

TARGET = mx-welcome
TEMPLATE = app

SOURCES += \
    main.cpp \
    about.cpp \
    flatbutton.cpp \
    mainwindow.cpp

HEADERS  += \
    about.h \
    flatbutton.h \
    mainwindow.h

FORMS    += \
    mainwindow.ui

TRANSLATIONS += \
    translations/mx-welcome_en.ts


