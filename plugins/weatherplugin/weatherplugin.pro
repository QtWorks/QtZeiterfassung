QT += core network gui widgets

TARGET = weatherplugin

DBLIBS += core gui

HEADERS += weatherplugin.h \
           weathersettings.h \
           weathersettingswidget.h \
           weatherwidget.h

SOURCES += weatherplugin.cpp \
           weathersettings.cpp \
           weathersettingswidget.cpp \
           weatherwidget.cpp

FORMS +=

RESOURCES +=

TRANSLATIONS += translations/weatherplugin_en.ts \
                translations/weatherplugin_de.ts

OTHER_FILES += weatherplugin.json

include(../plugin.pri)
