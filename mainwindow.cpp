#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

#define EBUTTONWIDTH 50
#define EBUTTONHEIGHT 25


MainWindow::MainWindow(int mWidth, int mHeight, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    {
        QString width;
        QString height;
        width.setNum(mWidth);
        height.setNum(mHeight);
        ui->labelRes->setGeometry(0,0,50,16);
        ui->labelRes->setText(width+":"+height);
        ui->labelRes->setLineWidth(100);

    }
    QPushButton *exitButton = new QPushButton("Exit",this);
    exitButton->setObjectName("exitButton");
    exitButton->setGeometry(mWidth-EBUTTONWIDTH, 0,EBUTTONWIDTH,EBUTTONHEIGHT);

}

MainWindow::~MainWindow()
{
    delete ui;
}

