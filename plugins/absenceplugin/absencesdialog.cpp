#include "absencesdialog.h"
#include "ui_absencesdialog.h"

#include <QDate>
#include <QLocale>
#include <QMessageBox>
#include <QStringBuilder>
#include <QMenu>
#include <QAction>

#include "absencesmodel.h"

AbsencesDialog::AbsencesDialog(int userId, const QDate &date, ZeiterfassungApi &erfassung, QWidget *parent) :
    ZeiterfassungDialog(parent),
    ui(new Ui::AbsencesDialog)
{
    ui->setupUi(this);

    ui->labelTitle->setText(tr("Absences for %0").arg(QLocale().toString(date)));

    m_model = new AbsencesModel(userId, date, erfassung, this);
    connect(m_model, &AbsencesModel::errorOccured, this, &AbsencesDialog::errorOccured);

    ui->treeView->setModel(m_model);
    ui->treeView->setEnabled(m_model->enabled());
    connect(m_model, &AbsencesModel::enabledChanged, ui->treeView, &QWidget::setEnabled);

    connect(ui->treeView, &QWidget::customContextMenuRequested, this, &AbsencesDialog::customContextMenuRequested);
}

AbsencesDialog::~AbsencesDialog()
{
    delete ui;
}

void AbsencesDialog::errorOccured(const QString &message)
{
    QMessageBox::warning(this, tr("Could not load absences!"), tr("Could not load absences!") % "\n\n" % message);
}

void AbsencesDialog::customContextMenuRequested(const QPoint &pos)
{
    auto index = ui->treeView->indexAt(pos);

    if(!index.isValid())
    {
        QMenu menu;
        auto createAction = menu.addAction(tr("Create absence"));
        auto refreshAction = menu.addAction(QIcon(QPixmap(QStringLiteral(":/zeiterfassungguilib/images/refresh.png"))), tr("Refresh absences"));
        auto selectedAction = menu.exec(ui->treeView->viewport()->mapToGlobal(pos));
        if(selectedAction == createAction)
        {
            //TODO
        }
        else if(selectedAction == refreshAction)
        {
            m_model->refresh();
        }
    }
    else
    {
        auto absence = m_model->absences().at(index.row());

        QMenu menu;
        auto editAction = menu.addAction(tr("Edit absence"));
        auto deleteAction = menu.addAction(tr("Delete absence"));
        auto selectedAction = menu.exec(ui->treeView->viewport()->mapToGlobal(pos));
        if(selectedAction == editAction)
        {
            //TODO
        }
        else if(selectedAction == deleteAction)
        {
            QMessageBox msgBox;
            msgBox.setText(tr("Do you really want to delete the absence?"));
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Cancel);
            if(msgBox.exec() == QMessageBox::Yes)
            {
                //TODO
            }
        }
    }
}
