QT += core network gui widgets

TARGET = devtoolsplugin

DBLIBS += core gui

HEADERS += devtoolsplugin.h \
           logdialog.h \
           logmodel.h

SOURCES += devtoolsplugin.cpp \
           logdialog.cpp \
           logmodel.cpp

FORMS += logdialog.ui

RESOURCES += devtoolsplugin_resources.qrc

TRANSLATIONS += translations/devtoolsplugin_en.ts \
                translations/devtoolsplugin_de.ts

OTHER_FILES += devtoolsplugin.json

include(../plugin.pri)
