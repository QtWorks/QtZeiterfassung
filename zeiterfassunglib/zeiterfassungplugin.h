#ifndef ZEITERFASSUNGPLUGIN_H
#define ZEITERFASSUNGPLUGIN_H

#include <QObject>

#include "zeiterfassunglib_global.h"

class ZEITERFASSUNGLIBSHARED_EXPORT ZeiterfassungPlugin : public QObject
{
    Q_OBJECT

public:
    explicit ZeiterfassungPlugin(QObject *parent = 0);

    virtual void initialize() = 0;
};

Q_DECLARE_INTERFACE(ZeiterfassungPlugin, "dbsoftware.zeiterfassung.plugin/1.0")

#endif // ZEITERFASSUNGPLUGIN_H
