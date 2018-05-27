#include "lunchmealdialog.h"
#include "ui_lunchmealdialog.h"

#include <QDate>
#include <QLocale>

LunchMealDialog::LunchMealDialog(const QDate &date, const QString &content, QWidget *parent) :
    ZeiterfassungDialog(parent),
    ui(new Ui::LunchMealDialog)
{
    ui->setupUi(this);

    ui->labelTitle->setText(tr("Lunch meal for %0").arg(QLocale().toString(date)));
    ui->labelLunchMeal->setText(content);
}

LunchMealDialog::~LunchMealDialog()
{
    delete ui;
}
