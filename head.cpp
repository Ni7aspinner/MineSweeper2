#include "head.h"
#include "ui_head.h"
#include <QPushButton>

Head::Head(int mWidth, int mHeight, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Head)
{
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::gray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->setFixedSize(mWidth,mHeight);

    ui->setupUi(this);

}

Head::~Head()
{
    delete ui;
}
