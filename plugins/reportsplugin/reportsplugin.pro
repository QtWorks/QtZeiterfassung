QT += core network gui widgets

TARGET = reportsplugin

DBLIBS += core gui

HEADERS += reportsplugin.h \
           reportswidget.h

SOURCES += reportsplugin.cpp \
           reportswidget.cpp

FORMS +=

RESOURCES += reportsplugin_resources.qrc

TRANSLATIONS += translations/reportsplugin_en.ts \
                translations/reportsplugin_de.ts

OTHER_FILES += reportsplugin.json

include(../plugin.pri)
