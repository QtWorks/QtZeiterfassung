#pragma once

#include "zeiterfassungdialog.h"

class QDate;

class ZeiterfassungApi;

class AbsencesModel;
namespace Ui { class AbsencesDialog; }

class AbsencesDialog : public ZeiterfassungDialog
{
    Q_OBJECT

public:
    explicit AbsencesDialog(int userId, const QDate &date, ZeiterfassungApi &erfassung, QWidget *parent = 0);
    ~AbsencesDialog();

private Q_SLOTS:
    void errorOccured(const QString &message);
    void customContextMenuRequested(const QPoint &pos);

private:
    Ui::AbsencesDialog *ui;

    AbsencesModel *m_model;
};
