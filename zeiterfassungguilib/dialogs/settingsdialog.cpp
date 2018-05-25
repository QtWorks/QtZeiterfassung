#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QMessageBox>
#include <QStringBuilder>
#include <QDir>
#include <QApplication>
#include <QSet>
#include <QFile>
#include <QTextStream>

#include "zeiterfassungsettings.h"
#include "zeiterfassungplugin.h"
#include "settingswidget.h"

SettingsDialog::SettingsDialog(ZeiterfassungSettings &settings, const QSet<ZeiterfassungPlugin*> &plugins, QWidget *parent) :
    ZeiterfassungDialog(parent),
    ui(new Ui::SettingsDialog),
    m_settings(settings)
{
    ui->setupUi(this);

    ui->comboBoxLanguage->addItem(tr("English"), QLocale::English);
    ui->comboBoxLanguage->addItem(tr("German"), QLocale::German);

    {
        auto index = ui->comboBoxLanguage->findData(m_settings.language());
        if(index == -1)
            QMessageBox::warning(this, tr("Invalid settings!"), tr("Invalid settings!") % "\n\n" % tr("Unknown language!"));
        ui->comboBoxLanguage->setCurrentIndex(index);
    }

    ui->comboBoxTheme->addItem(tr("Default"), QString());

    for(const auto &entry : QDir(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath(QStringLiteral("themes"))).entryInfoList(QStringList { QStringLiteral("*.qss") }, QDir::Files))
        ui->comboBoxTheme->addItem(entry.baseName(), entry.baseName());

    if(!m_settings.theme().isEmpty())
    {
        auto index = ui->comboBoxTheme->findData(m_settings.theme());
        if(index == -1)
            QMessageBox::warning(this, tr("Invalid settings!"), tr("Invalid settings!") % "\n\n" % tr("Unknown theme!"));
        ui->comboBoxTheme->setCurrentIndex(index);
    }

    for(const auto plugin : plugins)
    {
        auto widget = plugin->settingsWidget(m_settings, this);
        if(!widget)
            continue;

        ui->verticalLayout->addWidget(widget);
        m_settingsWidgets.append(widget);
    }

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::submit);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::submit()
{
    if(ui->comboBoxLanguage->currentIndex() == -1 ||
       ui->comboBoxTheme->currentIndex() == -1)
    {
        QMessageBox::warning(this, tr("Invalid settings!"), tr("Invalid settings!") % "\n\n" % tr("Please fill all options with valid values!"));
        return;
    }

    for(const auto widget : m_settingsWidgets)
    {
        QString message;
        if(!widget->isValid(message))
        {
            QMessageBox::warning(this, tr("Invalid settings!"), tr("Invalid settings!") % "\n\n" % message);
            return;
        }
    }

    if(ui->comboBoxLanguage->currentData().value<QLocale::Language>() != m_settings.language())
    {
        if(!m_settings.setLanguage(ui->comboBoxLanguage->currentData().value<QLocale::Language>()))
        {
            errorOccured();
            return;
        }

        //TODO #73 Allow changing of the language without restart
        QMessageBox::information(this, tr("Restart required!"), tr("To apply the new settings a restart is required!"));
    }

    auto theme = ui->comboBoxTheme->currentData().toString();
    if(theme != m_settings.theme())
    {
        QString styleSheet;
        if(!theme.isEmpty())
        {
            auto themePath = QDir(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath(QStringLiteral("themes"))).absoluteFilePath(theme);

            QFile file(themePath % ".qss");

            if(!file.exists())
            {
                QMessageBox::warning(this, tr("Could not load theme!"), tr("Could not load theme!") % "\n\n" % tr("Theme file does not exist!"));
                return;
            }

            if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QMessageBox::warning(this, tr("Could not load theme!"), tr("Could not load theme!") % "\n\n" % file.errorString());
                return;
            }

            QTextStream textStream(&file);
            styleSheet = textStream.readAll().replace(QStringLiteral("@THEME_RESOURCES@"), themePath);
        }

        if(!m_settings.setTheme(theme))
        {
            errorOccured();
            return;
        }

        qApp->setStyleSheet(styleSheet);
    }

    for(const auto widget : m_settingsWidgets)
    {
        if(!widget->apply())
        {
            errorOccured();
            return;
        }
    }

    accept();
}

void SettingsDialog::errorOccured()
{
    QMessageBox::warning(this, tr("Could not save settings!"), tr("Could not load settings!") % "\n\n" % tr("Make sure you have writing permissions!"));
}
