#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QFontDatabase>
#include <QScreen>
#include <QFile>
#include <QDir>
#include <random>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto resolution = QGuiApplication::screens()[0]->geometry();

    MainWindow *w = new MainWindow(resolution.width(),resolution.height());

    int id = QFontDatabase::addApplicationFont(":/font/minecraft.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug() << "Loaded font family:" << family;

    QString qssPath = QDir::cleanPath(":/style/styles.qss");
    QFile file(qssPath);

    if (file.open(QFile::ReadOnly)) {
        qDebug() << "Style file was found";
        QString styleSheet = QLatin1String(file.readAll());
        w->setStyleSheet(styleSheet);
    }

    w->setGeometry(QGuiApplication::screens()[0]->geometry());
    w->setWindowTitle("MINESWEEPER 2");


    w->showFullScreen();

    QPushButton *exitButton = w->findChild<QPushButton *>("exitButton");
    QObject::connect(exitButton, SIGNAL(clicked()), &a, SLOT(closeAllWindows()));

    return a.exec();
}
