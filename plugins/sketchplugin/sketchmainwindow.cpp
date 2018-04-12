#include "sketchmainwindow.h"
#include "ui_sketchmainwindow.h"

#include <QFileDialog>
#include <QStringBuilder>
#include <QMessageBox>
#include <QLabel>
#include <QGraphicsView>

#include "sketchfile.h"
#include "container/document.h"
#include "container/page.h"
#include "container/msjsonfilereference.h"

SketchMainWindow::SketchMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SketchMainWindow)
{
    ui->setupUi(this);

    ui->actionOpen->setShortcut(QKeySequence::Open);
    ui->actionQuit->setShortcut(QKeySequence::Quit);

    connect(ui->actionOpen, &QAction::triggered, this, &SketchMainWindow::openPressed);
}

SketchMainWindow::~SketchMainWindow()
{
    delete ui;
}

void SketchMainWindow::openPressed()
{
    auto filename = QFileDialog::getOpenFileName(this, tr("Select a sketch file"), QString(), QStringLiteral("%0 (*.sketch)").arg(tr("Sketch file")));
    if(filename.isEmpty())
        return;

    load(filename);
}

void SketchMainWindow::load(const QString &filename)
{
    while(ui->tabWidget->count())
    {
        auto widget = ui->tabWidget->widget(0);
        ui->tabWidget->removeTab(0);
        widget->deleteLater();
    }

    SketchFile file;
    try
    {
        file.open(filename);
    }
    catch(const QString &msg)
    {
        QMessageBox::warning(this, tr("Could not load sketch file!"), tr("Could not load sketch file!") % "\n\n" % msg);
        return;
    }

    for(auto pageRef : file.document()->pages())
    {
        Page *page;
        try
        {
            page = file.loadPage(pageRef->_ref());
        } catch (QString msg) {
            ui->tabWidget->addTab(new QLabel(QStringLiteral("<span style=\"color: red;\">Could not parse page: %0</span>").arg(msg), ui->tabWidget), pageRef->_ref());
            continue;
        }

        QGraphicsScene *scene;
        try
        {
            scene = file.createScene(page);
        } catch (QString msg) {
            ui->tabWidget->addTab(new QLabel(QStringLiteral("<span style=\"color: red;\">Could not render page: %0</span>").arg(msg), ui->tabWidget), page->name());
            continue;
        }

        ui->tabWidget->addTab(new QGraphicsView(scene, ui->tabWidget), page->name());
    }
}
