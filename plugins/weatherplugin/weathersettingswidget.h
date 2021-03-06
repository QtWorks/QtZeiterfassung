#pragma once

#include <QWidget>

#include "settingswidget.h"

#include "weathersettings.h"

class QLineEdit;

class ZeiterfassungSettings;

class WeatherSettingsWidget : public SettingsWidget
{
    Q_OBJECT

public:
    explicit WeatherSettingsWidget(ZeiterfassungSettings &settings, QWidget *parent = Q_NULLPTR);

    bool isValid(QString &message) const Q_DECL_OVERRIDE;

public Q_SLOTS:
    virtual bool apply() Q_DECL_OVERRIDE;

private:
    WeatherSettings m_settings;

    QLineEdit *m_lineEdit;
};
