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

    /*QPixmap bg(":/images/backgrounds/background.png");
    bg = bg.scaled(w->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bg);
    */
    std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distX(1, 8);
    QString bgPath = ":/images/backgrounds/Bg" +QString::number(distX(engine))+".PNG";
    QPixmap bg(bgPath);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(bg));
    w->setAutoFillBackground(true);
    w->setPalette(palette);

    w->showFullScreen();

    QPushButton *exitButton = w->findChild<QPushButton *>("exitButton");
    QObject::connect(exitButton, SIGNAL(clicked()), &a, SLOT(closeAllWindows()));

    return a.exec();
}
