#ifndef STRIPSWIDGET_H
#define STRIPSWIDGET_H

#include <QWidget>
#include <QTime>

#include "zeiterfassungapi.h"

class QBoxLayout;
template <class Key, class T> class QMap;
template <typename T> class QVector;

class StripFactory;
class GetBookingsReply;
class GetTimeAssignmentsReply;

class StripsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StripsWidget(ZeiterfassungApi &erfassung, int userId, StripFactory &stripFactory,
                          const QMap<QString, QString> &projects, QWidget *parent = Q_NULLPTR);

    const QDate &date() const;
    void setDate(const QDate &date);

    const QVector<ZeiterfassungApi::Booking> &bookings() const;
    const QVector<ZeiterfassungApi::TimeAssignment> &timeAssignments() const;

    const QTime &timeAssignmentTime() const;
    const QTime &lastTimeAssignmentStart() const;
    const QTime &minimumTime() const;
    bool refreshing() const;
    bool refreshingBookings() const;
    bool refreshingTimeAssignments() const;
    bool startEnabled() const;
    bool endEnabled() const;

    void refresh();
    void refreshBookings();
    void refreshTimeAssignments();
    bool createStrips();
    void clearStrips();

Q_SIGNALS:
    void bookingsChanged(const QVector<ZeiterfassungApi::Booking> &bookings);
    void timeAssignmentsChanged(const QVector<ZeiterfassungApi::TimeAssignment> &timeAssignments);

    void timeAssignmentTimeChanged(const QTime &timeAssignmentTime);
    void lastTimeAssignmentStartChanged(const QTime &lastTimeAssignmentStart);
    void minimumTimeChanged(const QTime &minimumTime);
    void refreshingChanged(bool refreshing);
    void refreshingBookingsChanged(bool refreshingBookings);
    void refreshingTimeAssignmentsChanged(bool refreshingTimeAssignments);
    void startEnabledChanged(bool startEnabled);
    void endEnabledChanged(bool endEnabled);

private Q_SLOTS:
    void getBookingsFinished();
    void getTimeAssignmentsFinished();

private:
    void invalidateValues();

    QString buildProjectString(const QString &project);

    QWidget *appendBookingStartStrip(int id, const QTime &time);
    QWidget *appendBookingEndStrip(int id, const QTime &time);
    QWidget *appendTimeAssignmentStrip(int id, const QTime &duration, const QString &project, const QString &subproject,
                                       const QString &workpackage, const QString &text);

    ZeiterfassungApi &m_erfassung;
    int m_userId;
    StripFactory &m_stripFactory;
    const QMap<QString, QString> &m_projects;

    QBoxLayout *m_layout;

    QDate m_date;

    QVector<ZeiterfassungApi::Booking> m_bookings;
    QVector<ZeiterfassungApi::TimeAssignment> m_timeAssignments;

    QTime m_timeAssignmentTime;
    QTime m_lastTimeAssignmentStart;
    QTime m_minimumTime;
    bool m_refreshing;
    bool m_refreshingBookings;
    bool m_refreshingTimeAssignments;
    bool m_startEnabled;
    bool m_endEnabled;

    GetBookingsReply *m_getBookingsReply;
    GetTimeAssignmentsReply *m_getTimeAssignmentsReply;
};

#endif // STRIPSWIDGET_H
