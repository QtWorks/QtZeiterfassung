QT += core network gui widgets

TARGET = favoritesplugin

DBLIBS += core gui

HEADERS += favoritesplugin.h

SOURCES += favoritesplugin.cpp

FORMS +=

RESOURCES += favoritesplugin_resources.qrc

TRANSLATIONS += translations/favoritesplugin_en.ts \
                translations/favoritesplugin_de.ts

OTHER_FILES += favoritesplugin.json

include(../plugin.pri)
