QT += core network gui widgets

TARGET = sketchplugin

DBLIBS += core gui

HEADERS += sketchplugin.h

SOURCES += sketchplugin.cpp

FORMS +=

RESOURCES += sketchplugin_resources.qrc

TRANSLATIONS += translations/sketchplugin_en.ts \
                translations/sketchplugin_de.ts

OTHER_FILES += sketchplugin.json

include(../plugin.pri)

include(QtSketch/sketchlib.pri)
