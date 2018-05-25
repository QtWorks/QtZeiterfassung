#pragma once

#include "settingswidget.h"

#include "presencesettings.h"

class QSpinBox;

class PresenceSettingsWidget : public SettingsWidget
{
    Q_OBJECT

public:
    explicit PresenceSettingsWidget(ZeiterfassungSettings &settings, QWidget *parent = Q_NULLPTR);

public Q_SLOTS:
    virtual bool apply() Q_DECL_OVERRIDE;

private:
    PresenceSettings m_settings;

    QSpinBox *m_spinBox;
};
