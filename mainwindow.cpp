#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

#define EBUTTONWIDTH 50
#define EBUTTONHEIGHT 25

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto exitButton = new QPushButton("Exit",this);
    exitButton->setGeometry(this->frameGeometry().width()-EBUTTONWIDTH, 0,EBUTTONWIDTH,EBUTTONHEIGHT);

}

MainWindow::~MainWindow()
{
    delete ui;
}
