QT += core network gui widgets multimedia

TARGET = webradioplugin

DBLIBS += core gui

HEADERS += webradiodialog.h \
           webradioplugin.h \
           webradiosettings.h \
           webradiosettingswidget.h

SOURCES += webradiodialog.cpp \
           webradioplugin.cpp \
           webradiosettings.cpp \
           webradiosettingswidget.cpp

FORMS += webradiodialog.ui

RESOURCES += webradioplugin_resources.qrc

TRANSLATIONS += translations/webradioplugin_en.ts \
                translations/webradioplugin_de.ts

OTHER_FILES += webradioplugin.json

include(../plugin.pri)
