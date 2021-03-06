#pragma once

#include <memory>

#include <QAbstractListModel>
#include <QDate>

#include "replies/getabsencesreply.h"

class ZeiterfassungApi;

class AbsencesModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ enabled NOTIFY enabledChanged)
    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)

public:
    explicit AbsencesModel(int userId, const QDate &date, ZeiterfassungApi &erfassung, QObject *parent = Q_NULLPTR);

    bool enabled() const;

    const QDate &date() const;

    const QVector<GetAbsencesReply::Absence> &absences() const;

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

Q_SIGNALS:
    void enabledChanged(bool enabled);
    void dateChanged(const QDate &date);
    void errorOccured(const QString &message);

public Q_SLOTS:
    void refresh();
    void setDate(const QDate &date);

private Q_SLOTS:
    void finished();

private:
    int m_userId;
    QDate m_date;
    ZeiterfassungApi &m_erfassung;
    std::unique_ptr<GetAbsencesReply> m_reply;
    QVector<GetAbsencesReply::Absence> m_absences;
};
