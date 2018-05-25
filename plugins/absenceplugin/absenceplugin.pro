QT += core network gui widgets

TARGET = absenceplugin

DBLIBS += core gui

HEADERS += \
           absencesmodel.h \
           absenceplugin.h \
           absencewidget.h \
    absencesdialog.h

SOURCES += \
           absencesmodel.cpp \
           absenceplugin.cpp \
           absencewidget.cpp \
    absencesdialog.cpp

FORMS += \
    absencesdialog.ui

RESOURCES += absenceplugin_resources.qrc

TRANSLATIONS += translations/absenceplugin_en.ts \
                translations/absenceplugin_de.ts

OTHER_FILES += absenceplugin.json

include(../plugin.pri)
