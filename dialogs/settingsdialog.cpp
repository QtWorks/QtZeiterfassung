#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QMessageBox>

#include "zeiterfassungsettings.h"

SettingsDialog::SettingsDialog(ZeiterfassungSettings &settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog),
    m_settings(settings)
{
    ui->setupUi(this);

    ui->comboBoxLanguage->addItem(tr("English"), QLocale::English);
    ui->comboBoxLanguage->addItem(tr("German"), QLocale::German);

    ui->comboBoxLanguage->setCurrentIndex(ui->comboBoxLanguage->findData(settings.language()));
    ui->lineEditBuchungStartBackgroundColor->setText(settings.buchungStartBackgroundColor());
    ui->lineEditBuchungEndBackgroundColor->setText(settings.buchungEndBackgroundColor());
    ui->lineEditBuchungOtherBackgroundColor->setText(settings.buchungOtherBackgroundColor());
    ui->lineEditTimeAssignmentBackgroundColor->setText(settings.timeAssignmentBackgroundColor());

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::submit);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::submit()
{
    if(ui->comboBoxLanguage->currentData().value<QLocale::Language>() != m_settings.language())
    {
        m_settings.setLanguage(ui->comboBoxLanguage->currentData().value<QLocale::Language>());
        QMessageBox::warning(this, tr("Restart required!"), tr("To apply the new language a restart is required!"));
    }
    if(ui->lineEditBuchungStartBackgroundColor->text() != m_settings.buchungStartBackgroundColor())
        m_settings.setBuchungStartBackgroundColor(ui->lineEditBuchungStartBackgroundColor->text());
    if(ui->lineEditBuchungEndBackgroundColor->text() != m_settings.buchungEndBackgroundColor())
        m_settings.setBuchungEndBackgroundColor(ui->lineEditBuchungEndBackgroundColor->text());
    if(ui->lineEditBuchungOtherBackgroundColor->text() != m_settings.buchungOtherBackgroundColor())
        m_settings.setBuchungOtherBackgroundColor(ui->lineEditBuchungOtherBackgroundColor->text());
    if(ui->lineEditTimeAssignmentBackgroundColor->text() != m_settings.timeAssignmentBackgroundColor())
        m_settings.setTimeAssignmentBackgroundColor(ui->lineEditTimeAssignmentBackgroundColor->text());

    accept();
}
