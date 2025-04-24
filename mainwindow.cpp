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
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    int vSize = (mWidth-mHeight)/2;

    head = new Head(mHeight,mHeight/5+5,this);
    head->move(vSize+1,0);

    game = new GameGrid(mWidth/3,3*mHeight/5+5,this);
    game->move(vSize+1,mHeight/5+5);

}

MainWindow::~MainWindow()
{
    delete ui;
}

