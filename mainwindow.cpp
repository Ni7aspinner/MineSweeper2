#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "head.h"
#include <QPushButton>


MainWindow::MainWindow(int mWidth, int mHeight, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    Head *head = new Head(mWidth,mHeight,this);

    ui->setupUi(this);
    ui->skeleton->addWidget(head);

}

MainWindow::~MainWindow()
{
    delete ui;
}

