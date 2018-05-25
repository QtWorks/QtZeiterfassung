#include "absencewidget.h"

#include "stripswidget.h"
#include "mainwindow.h"

#include "absencesdialog.h"

AbsenceWidget::AbsenceWidget(StripsWidget &stripsWidget) :
    QToolButton(&stripsWidget),
    m_stripsWidget(stripsWidget)
{
    setIcon(QIcon(QStringLiteral(":/zeiterfassung/plugins/absenceplugin/images/absence.png")));
    setText(tr("Absence"));

    connect(this, &QAbstractButton::pressed, this, &AbsenceWidget::pressedSlot);
}

void AbsenceWidget::pressedSlot()
{
    AbsencesDialog dialog(m_stripsWidget.mainWindow().userInfo().userId, m_stripsWidget.date(),
                         m_stripsWidget.mainWindow().erfassung(), this);
    dialog.exec();
}
