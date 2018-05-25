#include "weathersettings.h"

#include "zeiterfassungsettings.h"

const QString WeatherSettings::m_url("WeatherPlugin/url");
const QUrl WeatherSettings::m_defaultUrl(QStringLiteral("http://api.openweathermap.org/data/2.5/weather?q=Graz,AT&units=metric&APPID=40f6c892c6162680c6c9235169dc9f83"));

WeatherSettings::WeatherSettings(ZeiterfassungSettings &settings, QObject *parent) :
    QObject(parent),
    m_settings(settings)
{

}

QUrl WeatherSettings::url() const
{
    return m_settings.value(m_url, m_defaultUrl).toUrl();
}

bool WeatherSettings::setUrl(const QUrl &url)
{
    if(this->url() == url)
        return true;

    m_settings.setValue(m_url, url);

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
