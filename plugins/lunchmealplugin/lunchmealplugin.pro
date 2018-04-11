QT += core network gui widgets

TARGET = lunchmealplugin

DBLIBS += core gui

HEADERS += lunchmealdialog.h \
           lunchmealsettings.h \
           lunchmealsettingswidget.h \
           lunchmealplugin.h \
           lunchmealwidget.h

SOURCES += lunchmealdialog.cpp \
           lunchmealsettings.cpp \
           lunchmealsettingswidget.cpp \
           lunchmealplugin.cpp \
           lunchmealwidget.cpp

FORMS += lunchmealdialog.ui

RESOURCES += lunchmealplugin_resources.qrc

TRANSLATIONS += translations/lunchmealplugin_en.ts \
                translations/lunchmealplugin_de.ts

OTHER_FILES += lunchmealplugin.json

include(../plugin.pri)
