QT += core network gui widgets

TARGET = profileplugin

DBLIBS += core gui

HEADERS += profiledialog.h \
           profileplugin.h

SOURCES += profiledialog.cpp \
           profileplugin.cpp

FORMS += profiledialog.ui

RESOURCES += profileplugin_resources.qrc

TRANSLATIONS += translations/profileplugin_en.ts \
                translations/profileplugin_de.ts

OTHER_FILES += profileplugin.json

include(../plugin.pri)
