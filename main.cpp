#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QScreen>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto resolution = QGuiApplication::screens()[0]->geometry();

    MainWindow *w = new MainWindow(resolution.width(),resolution.height());

    QString qssPath = QDir::cleanPath(QApplication::applicationDirPath() + "/../../styles.qss");
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
