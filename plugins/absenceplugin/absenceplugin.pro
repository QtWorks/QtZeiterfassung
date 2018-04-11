QT += core network gui widgets

TARGET = absenceplugin

DBLIBS += core gui

HEADERS += absencedialog.h \
           absencesmodel.h \
           absenceplugin.h \
           absencewidget.h

SOURCES += absencedialog.cpp \
           absencesmodel.cpp \
           absenceplugin.cpp \
           absencewidget.cpp

FORMS += absencedialog.ui

RESOURCES += absenceplugin_resources.qrc

TRANSLATIONS += translations/absenceplugin_en.ts \
                translations/absenceplugin_de.ts

OTHER_FILES += absenceplugin.json

include(../plugin.pri)
