#pragma once

#include "settingswidget.h"

#include "lunchmealsettings.h"

class QLineEdit;

class LunchMealSettingsWidget : public SettingsWidget
{
    Q_OBJECT

public:
    explicit LunchMealSettingsWidget(ZeiterfassungSettings &settings, QWidget *parent = Q_NULLPTR);

    virtual bool isValid(QString &message) const Q_DECL_OVERRIDE;

public Q_SLOTS:
    virtual bool apply() Q_DECL_OVERRIDE;

private:
    LunchMealSettings m_settings;

    QLineEdit *m_lineEditUrl;
    QLineEdit *m_lineEditDateFormat;
};
