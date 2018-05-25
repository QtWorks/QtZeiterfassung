#include "updatersettings.h"

#include "zeiterfassungsettings.h"

const QString UpdaterSettings::m_url("UpdaterPlugin/url");
const QString UpdaterSettings::m_lastUpdateCheck("UpdaterPlugin/lastUpdateCheck");
const QUrl UpdaterSettings::m_defaultUrl(QStringLiteral("https://api.github.com/repos/0xFEEDC0DE64/QtZeiterfassung/releases"));

UpdaterSettings::UpdaterSettings(ZeiterfassungSettings &settings, QObject *parent) :
    QObject(parent),
    m_settings(settings)
{

}

QUrl UpdaterSettings::url() const
{
    return m_settings.value(m_url, m_defaultUrl).toUrl();
}

bool UpdaterSettings::setUrl(const QUrl &url)
{
    if(this->url() == url)
        return true;

    if(url == m_defaultUrl)
        m_settings.remove(m_url);
    else
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

QDate UpdaterSettings::lastUpdateCheck() const
{
    return m_settings.value(m_lastUpdateCheck).toDate();
}

bool UpdaterSettings::setLastUpdateCheck(const QDate &lastUpdateCheck)
{
    if(this->lastUpdateCheck() == lastUpdateCheck)
        return true;

    if(!lastUpdateCheck.isValid())
        m_settings.remove(m_lastUpdateCheck);
    else
        m_settings.setValue(m_lastUpdateCheck, lastUpdateCheck);

    m_settings.sync();

    const auto success = m_settings.status() == QSettings::NoError;
    if(success)
        Q_EMIT lastUpdateCheckChanged(lastUpdateCheck);
    else
    {
        Q_EMIT m_settings.saveErrorOccured();
        Q_EMIT saveErrorOccured();
    }

    return success;
}
