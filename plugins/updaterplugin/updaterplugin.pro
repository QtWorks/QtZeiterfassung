QT += core network gui widgets

TARGET = updaterplugin

DBLIBS += core gui

HEADERS += updaterdialog.h \
           updaterplugin.h \
           updatersettings.h \
           updatersettingswidget.h

SOURCES += updaterdialog.cpp \
           updaterplugin.cpp \
           updatersettings.cpp \
           updatersettingswidget.cpp

FORMS += updaterdialog.ui

RESOURCES +=

TRANSLATIONS += translations/updaterplugin_en.ts \
                translations/updaterplugin_de.ts

OTHER_FILES += updaterplugin.json

include(../plugin.pri)
