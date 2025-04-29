#include "head.h"
#include "ui_head.h"
#include <QPushButton>
#include <qprogressdialog.h>
#include <qboxlayout.h>


Head::Head(int mWidth, int mHeight, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Head)
{
    this->setAutoFillBackground(true);

    this->setFixedSize(mWidth,mHeight);

    ui->setupUi(this);
}

Head::~Head()
{
    delete ui;
}
