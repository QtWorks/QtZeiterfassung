#include "zeiterfassungsettings.h"

#include <QDebug>

const QString ZeiterfassungSettings::m_language("language");
const QString ZeiterfassungSettings::m_url("url");
const QString ZeiterfassungSettings::m_username("username");
const QString ZeiterfassungSettings::m_password("password");
const QString ZeiterfassungSettings::m_projects("projects");
const QString ZeiterfassungSettings::m_subprojects("subprojects");
const QString ZeiterfassungSettings::m_workpackages("workpackages");
const QString ZeiterfassungSettings::m_texts("texte");
const QString ZeiterfassungSettings::m_theme("theme");
const QLocale::Language ZeiterfassungSettings::m_defaultLanguage(QLocale::AnyLanguage);
const QUrl ZeiterfassungSettings::m_defaultUrl(QStringLiteral("http://10.1.0.11:8080/evoApps/"));

ZeiterfassungSettings::ZeiterfassungSettings(const QString &organization,
                                             const QString &application, QObject *parent) :
    QSettings(organization, application, parent)
{

}

ZeiterfassungSettings::ZeiterfassungSettings(QSettings::Scope scope, const QString &organization,
                                             const QString &application, QObject *parent) :
    QSettings(scope, organization, application, parent)
{

}

ZeiterfassungSettings::ZeiterfassungSettings(QSettings::Format format, QSettings::Scope scope, const QString &organization, const QString &application, QObject *parent) :
    QSettings(format, scope, organization, application, parent)
{

}

ZeiterfassungSettings::ZeiterfassungSettings(const QString &fileName, QSettings::Format format, QObject *parent) :
    QSettings(fileName, format, parent)
{

}

ZeiterfassungSettings::ZeiterfassungSettings(QObject *parent) :
    QSettings(parent)
{
}

QLocale::Language ZeiterfassungSettings::language() const
{
    return value(m_language, m_defaultLanguage).value<QLocale::Language>();
}

bool ZeiterfassungSettings::setLanguage(QLocale::Language language)
{
    if(this->language() == language)
        return true;

    if(m_defaultLanguage == language)
        remove(m_language);
    else
        setValue(m_language, language);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT languageChanged(language);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

QUrl ZeiterfassungSettings::url() const
{
    return value(m_url, m_defaultUrl).toUrl();
}

bool ZeiterfassungSettings::setUrl(const QUrl &url)
{
    if(this->url() == url)
        return true;

    if(m_defaultUrl == url)
        remove(m_url);
    else
        setValue(m_url, url);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT urlChanged(url);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

QString ZeiterfassungSettings::username() const
{
    return value(m_username).toString();
}

bool ZeiterfassungSettings::setUsername(const QString &username)
{
    if(this->username() == username)
        return true;

    if(username.isEmpty())
        remove(m_username);
    else
        setValue(m_username, username);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT usernameChanged(username);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

QString ZeiterfassungSettings::password() const
{
    return value(m_password).toString();
}

bool ZeiterfassungSettings::setPassword(const QString &password)
{
    if(this->password() == password)
        return true;

    if(password.isEmpty())
        remove(m_password);
    else
        setValue(m_password, password);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT passwordChanged(password);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

QStringList ZeiterfassungSettings::projects() const
{
    return value(m_projects).toStringList();
}

bool ZeiterfassungSettings::setProjects(const QStringList &projects)
{
    if(this->projects() == projects)
        return true;

    if(projects.isEmpty())
        remove(m_projects);
    else
        setValue(m_projects, projects);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT projectsChanged(projects);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

bool ZeiterfassungSettings::prependProject(const QString &project)
{
    return setProjects(prependItem(projects(), project));
}

QStringList ZeiterfassungSettings::subprojects() const
{
    return value(m_subprojects).toStringList();
}

bool ZeiterfassungSettings::setSubprojects(const QStringList &subprojects)
{
    if(this->subprojects() == subprojects)
        return true;

    if(subprojects.isEmpty())
        remove(m_subprojects);
    else
        setValue(m_subprojects, subprojects);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT subprojectsChanged(subprojects);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

bool ZeiterfassungSettings::prependSubproject(const QString &subproject)
{
    return setSubprojects(prependItem(subprojects(), subproject));
}

QStringList ZeiterfassungSettings::workpackages() const
{
    return value(m_workpackages).toStringList();
}

bool ZeiterfassungSettings::setWorkpackages(const QStringList &workpackages)
{
    if(this->workpackages() == workpackages)
        return true;

    if(workpackages.isEmpty())
        remove(m_workpackages);
    else
        setValue(m_workpackages, workpackages);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT workpackagesChanged(workpackages);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

bool ZeiterfassungSettings::prependWorkpackage(const QString &workpackage)
{
    return setWorkpackages(prependItem(workpackages(), workpackage));
}

QStringList ZeiterfassungSettings::texts() const
{
    return value(m_texts).toStringList();
}

bool ZeiterfassungSettings::setTexts(const QStringList &texts)
{
    if(this->texts() == texts)
        return true;

    if(m_texts.isEmpty())
        remove(m_texts);
    else
        setValue(m_texts, texts);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT textsChanged(texts);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

bool ZeiterfassungSettings::prependText(const QString &text)
{
    return setTexts(prependItem(texts(), text));
}

QString ZeiterfassungSettings::theme() const
{
    return value(m_theme).toString();
}

bool ZeiterfassungSettings::setTheme(const QString &theme)
{
    if(this->theme() == theme)
        return true;

    if(theme.isEmpty())
        remove(m_theme);
    else
        setValue(m_theme, theme);

    sync();

    const auto success = status() == QSettings::NoError;
    if(success)
        Q_EMIT themeChanged(theme);
    else
        Q_EMIT saveErrorOccured();

    return success;
}

QStringList ZeiterfassungSettings::prependItem(QStringList list, const QString &item)
{
    if(item.trimmed().isEmpty())
        return list;

    list.removeAll(item);
    list.prepend(item);

    return list;
}
