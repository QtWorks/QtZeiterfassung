#include "sketchplugin.h"

#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include <QLocale>
#include <QMenu>
#include <QAction>

#include "mainwindow.h"
#include "sketchmainwindow.h"

SketchPlugin::SketchPlugin(QObject *parent) :
    ZeiterfassungPlugin(parent)
{
    qDebug() << "called";

    static auto dir = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath(QStringLiteral("translations"));

    if(m_translator.load(QLocale(), QStringLiteral("sketchplugin"), QStringLiteral("_"), dir))
    {
        if(!QCoreApplication::installTranslator(&m_translator))
        {
            qWarning() << "could not install translation sketchplugin";
        }
    }
    else
    {
        qWarning() << "could not load translation sketchplugin";
    }
}

void SketchPlugin::attachTo(MainWindow &mainWindow)
{
    mainWindow.menuTools()->addAction(QIcon(QStringLiteral(":/zeiterfassung/plugins/sketchplugin/images/sketch.png")), tr("Open Sketch viewer"),
                                      this, &SketchPlugin::openWindow);
}

void SketchPlugin::openWindow()
{
    auto window = new SketchMainWindow;
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
}
