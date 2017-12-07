#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;

class ZeiterfassungSettings;
namespace Ui { class UpdateDialog; }

class UpdateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateDialog(ZeiterfassungSettings &settings, QNetworkAccessManager *manager, QWidget *parent = 0);
    ~UpdateDialog();

private Q_SLOTS:
    void finished();
    void submit();

private:
    Ui::UpdateDialog *ui;
    ZeiterfassungSettings &m_settings;
    QNetworkReply *m_reply;

    QUrl m_url;
};

#endif // UPDATEDIALOG_H