#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto resolution = QGuiApplication::screens()[1]->geometry();
    MainWindow *w = new MainWindow(resolution.width(),resolution.height());
    w->setGeometry(QGuiApplication::screens()[1]->geometry());
    w->setWindowTitle("MINESWEEPER 2");
    w->showFullScreen();
    QPushButton *exitButton = w->findChild<QPushButton *>("exitButton");
    QObject::connect(exitButton, SIGNAL(clicked()), &a, SLOT(closeAllWindows()));
    return a.exec();
}
