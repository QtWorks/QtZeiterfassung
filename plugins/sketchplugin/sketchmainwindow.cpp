#include "sketchmainwindow.h"
#include "ui_sketchmainwindow.h"

#include <QFileDialog>

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
    QFileDialog::getOpenFileName(this, tr("Select a sketch file"), QString(), QStringLiteral("%0 (*.sketch)").arg(tr("Sketch file")));
}
