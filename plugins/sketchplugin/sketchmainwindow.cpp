#include "sketchmainwindow.h"
#include "ui_sketchmainwindow.h"

SketchMainWindow::SketchMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SketchMainWindow)
{
    ui->setupUi(this);
}

SketchMainWindow::~SketchMainWindow()
{
    delete ui;
}
