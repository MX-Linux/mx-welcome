# **********************************************************************
# * Copyright (C) 2015 MX Authors
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

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mx-welcome
TEMPLATE = app


SOURCES += main.cpp\
    flatbutton.cpp \
    mainwindow.cpp

HEADERS  += \
    flatbutton.h \
    mainwindow.h

FORMS    += \
    mainwindow.ui

TRANSLATIONS += translations/mx-welcome_am.ts \
                translations/mx-welcome_ar.ts \
                translations/mx-welcome_bg.ts \
                translations/mx-welcome_ca.ts \
                translations/mx-welcome_cs.ts \
                translations/mx-welcome_da.ts \
                translations/mx-welcome_de.ts \
                translations/mx-welcome_el.ts \
                translations/mx-welcome_es.ts \
                translations/mx-welcome_et.ts \
                translations/mx-welcome_eu.ts \
                translations/mx-welcome_fa.ts \
                translations/mx-welcome_fi.ts \
                translations/mx-welcome_fr.ts \
                translations/mx-welcome_he_IL.ts \
                translations/mx-welcome_hi.ts \
                translations/mx-welcome_hr.ts \
                translations/mx-welcome_hu.ts \
                translations/mx-welcome_id.ts \
                translations/mx-welcome_is.ts \
                translations/mx-welcome_it.ts \
                translations/mx-welcome_ja.ts \
                translations/mx-welcome_kk.ts \
                translations/mx-welcome_ko.ts \
                translations/mx-welcome_lt.ts \
                translations/mx-welcome_mk.ts \
                translations/mx-welcome_mr.ts \
                translations/mx-welcome_nb.ts \
                translations/mx-welcome_nl.ts \
                translations/mx-welcome_pl.ts \
                translations/mx-welcome_pt.ts \
                translations/mx-welcome_pt_BR.ts \
                translations/mx-welcome_ro.ts \
                translations/mx-welcome_ru.ts \
                translations/mx-welcome_sk.ts \
                translations/mx-welcome_sl.ts \
                translations/mx-welcome_sq.ts \
                translations/mx-welcome_sr.ts \
                translations/mx-welcome_sv.ts \
                translations/mx-welcome_tr.ts \
                translations/mx-welcome_uk.ts \
                translations/mx-welcome_zh_CN.ts \
                translations/mx-welcome_zh_TW.ts

RESOURCES +=


