#pragma once

#include <memory>

#include <QString>
#include <QDate>
#include <QNetworkReply>
#include <QVector>

#include "zeiterfassungcorelib_global.h"
#include "zeiterfassungreply.h"

class ZeiterfassungApi;

class ZEITERFASSUNGCORELIBSHARED_EXPORT GetAbsencesReply : public ZeiterfassungReply
{
    Q_OBJECT

public:
    explicit GetAbsencesReply(std::unique_ptr<QNetworkReply> &&reply, ZeiterfassungApi *zeiterfassung);

    struct Absence
    {
        QString compositeId;
        int persNr;
        QDate start;
        QDate end;
        QString hourCategory;
        QString openMarking;
        int representative;
        int altRepresentative;
        QString text;
    };

    const QVector<Absence> &absences() const;

private Q_SLOTS:
    void requestFinished();

private:
    std::unique_ptr<QNetworkReply> m_reply;
    QVector<Absence> m_absences;
};
