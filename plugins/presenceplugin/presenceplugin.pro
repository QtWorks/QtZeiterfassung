QT += core network gui widgets

TARGET = presenceplugin

DBLIBS += core gui

HEADERS += presenceplugin.h \
           presencewidget.h \
    presencesettings.h \
    presencesettingswidget.h

SOURCES += presenceplugin.cpp \
           presencewidget.cpp \
    presencesettings.cpp \
    presencesettingswidget.cpp

FORMS +=

RESOURCES += presenceplugin_resources.qrc

TRANSLATIONS += translations/presenceplugin_en.ts \
                translations/presenceplugin_de.ts

OTHER_FILES += presenceplugin.json

include(../plugin.pri)
