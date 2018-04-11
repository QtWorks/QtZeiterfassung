QT += core network gui widgets

TARGET = zeiterfassung
TEMPLATE = app

CONFIG -= app_bundle

PROJECT_ROOT = ..

DESTDIR = $${OUT_PWD}/$${PROJECT_ROOT}/bin

DBLIBS += core gui

RC_ICONS = icon.ico

SOURCES += main.cpp

HEADERS +=

FORMS += strips/bookingstartstrip.ui \
         strips/bookingendstrip.ui \
         strips/timeassignmentstrip.ui

RESOURCES += zeiterfassung_resources.qrc

TRANSLATIONS += translations/zeiterfassung_en.ts \
                translations/zeiterfassung_de.ts

include($${PROJECT_ROOT}/project.pri)

include(installs.pri)
