#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamegrid.h"
#include "head.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:

    MainWindow(int mWidth=1920, int mHeight=1080, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Head *head;
    GameGrid *game;
};
#endif
