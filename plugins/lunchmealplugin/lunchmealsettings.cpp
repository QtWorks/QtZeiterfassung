#include "lunchmealsettings.h"

#include "zeiterfassungsettings.h"

const QString LunchMealSettings::m_url("LunchMealPlugin/url");
const QString LunchMealSettings::m_dateFormat("LunchMealPlugin/dateFormat");
const QString LunchMealSettings::m_defaultUrl("https://brunner.ninja/lunch/%0.txt");
const QString LunchMealSettings::m_defaultDateFormat("yyyy-MM-dd");

LunchMealSettings::LunchMealSettings(ZeiterfassungSettings &settings, QObject *parent) :
    QObject(parent),
    m_settings(settings)
{

}

QString LunchMealSettings::url() const
{
    return m_settings.value(m_url, m_defaultUrl).toString();
}

bool LunchMealSettings::setUrl(const QString &url)
{
    if(this->url() == url)
        return true;

    m_settings.setValue(QStringLiteral("LunchMealPlugin/url"), url);

    m_settings.sync();

    const auto success = m_settings.status() == QSettings::NoError;
    if(success)
        Q_EMIT urlChanged(url);
    else
    {
        Q_EMIT m_settings.saveErrorOccured();
        Q_EMIT saveErrorOccured();
    }

    return success;
}

QString LunchMealSettings::dateFormat() const
{
    return m_settings.value(m_dateFormat, m_defaultDateFormat).toString();
}

bool LunchMealSettings::setDateFormat(const QString &dateFormat)
{
    if(this->dateFormat() == dateFormat)
        return true;

    m_settings.setValue(QStringLiteral("LunchMealPlugin/dateFormat"), dateFormat);

    m_settings.sync();

    const auto success = m_settings.status() == QSettings::NoError;
    if(success)
        Q_EMIT dateFormatChanged(dateFormat);
    else
    {
        Q_EMIT m_settings.saveErrorOccured();
        Q_EMIT saveErrorOccured();
    }

    return success;
}
