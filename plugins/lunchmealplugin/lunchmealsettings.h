#pragma once

#include <QObject>
#include <QUrl>

class ZeiterfassungSettings;

class LunchMealSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QString dateFormat READ dateFormat WRITE setDateFormat NOTIFY dateFormatChanged)

public:
    LunchMealSettings(ZeiterfassungSettings &settings, QObject *parent = Q_NULLPTR);

    // no QString becuase placeholder %0 encodes wrong in urls!
    QString url() const;
    bool setUrl(const QString &url);

    QString dateFormat() const;
    bool setDateFormat(const QString &dateFormat);

Q_SIGNALS:
    void saveErrorOccured();

    void urlChanged(const QString &url);
    void dateFormatChanged(const QString &dateFormat);

private:
    ZeiterfassungSettings &m_settings;

    static const QString m_url;
    static const QString m_dateFormat;
    static const QString m_defaultUrl;
    static const QString m_defaultDateFormat;
};
