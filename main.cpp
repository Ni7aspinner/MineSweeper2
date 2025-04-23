#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QAction>
#include <QKeyEvent>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MINESWEEPER 2");
    QPushButton button ("Hello world",&w);
    w.showFullScreen();
    return a.exec();
}
