QT += core network gui widgets

TARGET = sketchplugin

DBLIBS += core gui

HEADERS += sketchmainwindow.h \
           sketchplugin.h

SOURCES += sketchmainwindow.cpp \
           sketchplugin.cpp

FORMS += sketchmainwindow.ui

RESOURCES += sketchplugin_resources.qrc

TRANSLATIONS += translations/sketchplugin_en.ts \
                translations/sketchplugin_de.ts

OTHER_FILES += sketchplugin.json

include(../plugin.pri)

include(QtSketch/sketchlib.pri)
