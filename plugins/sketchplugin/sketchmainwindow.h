#ifndef SKETCHMAINWINDOW_H
#define SKETCHMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class SketchMainWindow;
}

class SketchMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SketchMainWindow(QWidget *parent = 0);
    ~SketchMainWindow();

private Q_SLOTS:
    void openPressed();

private:
    Ui::SketchMainWindow *ui;
};

#endif // SKETCHMAINWINDOW_H
