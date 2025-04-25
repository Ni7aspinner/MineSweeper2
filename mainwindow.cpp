#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "head.h"
#include "gamegrid.h"
#include <QPushButton>

#define EBTNWIDTH 40
#define EBTNHEIGHT 30

Head *head;
GameGrid *game;

MainWindow::MainWindow(int mWidth, int mHeight, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(mWidth,mHeight);

    ui->setupUi(this);

    QString resolution = QString::number(this->size().width())+":"+QString::number(this->size().height());
    ui->labelRes->setText(resolution);
    ui->labelRes->setGeometry(0,0,50,15);
    ui->exitButton->setGeometry(mWidth-EBTNWIDTH, 0, EBTNWIDTH, EBTNHEIGHT);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::darkGray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    int vSize = (mWidth-mHeight)/2;
    int pixW = mHeight%13;
    mWidth = mHeight-pixW+14;

    QWidget *container = new QWidget(this);
    container->setGeometry(vSize,0,mWidth,mHeight);
    QVBoxLayout *mainLayout = new QVBoxLayout(container);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    head = new Head(mWidth,mHeight/8);

    int pixH = (19*mHeight/24)%10;
    game = new GameGrid(mWidth,(19*mHeight/24)-pixH+11);

    auto headTemp = new Head(mWidth,mHeight/12);


    qDebug() << "GameGrid constructed at" << game->geometry();

    mainLayout->addWidget(head);
    mainLayout->addWidget(game);
    mainLayout->addWidget(headTemp);
    game->raise();

}

MainWindow::~MainWindow()
{
    delete ui;
}

