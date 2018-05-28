#pragma once

#include <memory>

#include <QObject>
#include <QUrl>
#include <QString>
#include <QDate>
#include <QTime>

#include "zeiterfassungcorelib_global.h"

class QNetworkAccessManager;

class LoginPageReply;
class LoginReply;
class GetUserInfoReply;
class GetBookingsReply;
class CreateBookingReply;
class UpdateBookingReply;
class DeleteBookingReply;
class GetTimeAssignmentsReply;
class CreateTimeAssignmentReply;
class UpdateTimeAssignmentReply;
class DeleteTimeAssignmentReply;
class GetProjectsReply;
class GetReportReply;
class GetPresenceStatusReply;
class GetAbsencesReply;
class GetDayinfoReply;

class ZEITERFASSUNGCORELIBSHARED_EXPORT ZeiterfassungApi : public QObject
{
    Q_OBJECT

public:
    explicit ZeiterfassungApi(const QUrl &url, QObject *parent = Q_NULLPTR);

    const QUrl &url() const;
    void setUrl(const QUrl &url);

    QNetworkAccessManager *manager() const;

    std::unique_ptr<LoginPageReply> doLoginPage();
    std::unique_ptr<LoginReply> doLogin(const QString &username, const QString &password);
    std::unique_ptr<GetUserInfoReply> doUserInfo();

    std::unique_ptr<GetBookingsReply> doGetBookings(int userId, const QDate &start, const QDate &end);
    std::unique_ptr<CreateBookingReply> doCreateBooking(int userId, const QDate &date, const QTime &time, const QTime &timespan,
                                                        const QString &type, const QString &text);
    std::unique_ptr<UpdateBookingReply> doUpdateBooking(int bookingId, int userId, const QDate &date, const QTime &time,
                                                        const QTime &timespan, const QString &type, const QString &text);
    std::unique_ptr<DeleteBookingReply> doDeleteBooking(int bookingId);

    std::unique_ptr<GetTimeAssignmentsReply> doGetTimeAssignments(int userId, const QDate &start, const QDate &end);
    std::unique_ptr<CreateTimeAssignmentReply> doCreateTimeAssignment(int userId, const QDate &date, const QTime &time,
                                                                      const QTime &timespan, const QString &project,
                                                                      const QString &subproject, const QString &workpackage,
                                                                      const QString &text);
    std::unique_ptr<UpdateTimeAssignmentReply> doUpdateTimeAssignment(int timeAssignmentId, int userId, const QDate &date,
                                                                      const QTime &time, const QTime &timespan, const QString &project,
                                                                      const QString &subproject, const QString &workpackage,
                                                                      const QString &text);
    std::unique_ptr<DeleteTimeAssignmentReply> doDeleteTimeAssignment(int timeAssignmentId);

    std::unique_ptr<GetProjectsReply> doGetProjects(int userId, const QDate &date);
    std::unique_ptr<GetReportReply> doGetReport(int userId, const QDate &date);
    std::unique_ptr<GetPresenceStatusReply> doGetPresenceStatus();

    std::unique_ptr<GetAbsencesReply> doGetAbsences(int userId, const QDate &start, const QDate &end);
    std::unique_ptr<GetDayinfoReply> doGetDayinfo(int userId, const QDate &start, const QDate &end);

private:
    static QString formatDate(const QDate &date);
    static QString formatTime(const QTime &time);

    QUrl m_url;
    QNetworkAccessManager *m_manager;
};
