#include "buchungstrip.h"
#include "ui_buchungstrip.h"

#include <QTime>

BuchungStrip::BuchungStrip(int id, const QTime &time, const QString &type, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::BuchungStrip)
{
    ui->setupUi(this);

    setMinimumHeight(minimumSizeHint().height());
    setMaximumHeight(minimumSizeHint().height());

    ui->labelTime->setText(time.toString("HH:mm"));
    if(type == QStringLiteral("K"))
    {
        setStyleSheet("background-color: #7FFF7F;");
        ui->labelType->setText(tr("KOMMEN"));
    }
    else if(type == QStringLiteral("G"))
    {
        setStyleSheet("background-color: #FF7F7F;");
        ui->labelType->setText(tr("GEHEN"));
    }
    else
    {
        setStyleSheet("background-color: #FFFF7F;");
        ui->labelType->setText(tr("UNKNOWN"));
    }

    ui->labelId->setText(QString::number(id));
}

BuchungStrip::~BuchungStrip()
{
    delete ui;
}
