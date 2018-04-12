#pragma once

#include <QObject>
#include <QTranslator>

#include "zeiterfassungplugin.h"

class Q_DECL_EXPORT FavoritesPlugin : public ZeiterfassungPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "dbsoftware.zeiterfassung.plugin/1.0" FILE "favoritesplugin.json")
    Q_INTERFACES(ZeiterfassungPlugin)

public:
    explicit FavoritesPlugin(QObject *parent = Q_NULLPTR);

    // ZeiterfassungPlugin interface
    void attachTo(MainWindow &mainWindow) Q_DECL_OVERRIDE;

private:
    QTranslator m_translator;
};
