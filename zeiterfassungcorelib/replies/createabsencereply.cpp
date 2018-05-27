#include "createabsencereply.h"

#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

CreateAbsenceReply::CreateAbsenceReply(std::unique_ptr<QNetworkReply> &&reply, ZeiterfassungApi *zeiterfassung) :
    ZeiterfassungReply(zeiterfassung),
    m_reply(std::move(reply))
{
    connect(m_reply.get(), &QNetworkReply::finished, this, &CreateAbsenceReply::requestFinished);
}

void CreateAbsenceReply::requestFinished()
{
    if(m_reply->error() != QNetworkReply::NoError)
    {
        setSuccess(false);
        setMessage(tr("Request error occured: %0").arg(m_reply->errorString()));
        goto end;
    }

    {
        QJsonParseError error;
        QJsonDocument document = QJsonDocument::fromJson(m_reply->readAll(), &error);
        if(error.error != QJsonParseError::NoError)
        {
            setSuccess(false);
            setMessage(tr("Parsing JSON failed: %0").arg(error.errorString()));
            goto end;
        }

        if(!document.isObject())
        {
            setSuccess(false);
            setMessage(tr("JSON document is not an array!"));
            goto end;
        }

        auto obj = document.object();

        if(!obj.contains(QStringLiteral("compositeId")))
        {
            setSuccess(false);
            setMessage(tr("JSON does not contain compositeId!"));
            goto end;
        }

        m_compositeId = obj.value(QStringLiteral("compositeId")).toString();

        setSuccess(true);
    }

    end:
    m_reply = Q_NULLPTR;

    Q_EMIT finished();
}
