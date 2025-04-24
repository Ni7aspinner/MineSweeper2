#include "head.h"
#include "ui_head.h"
#include <QPushButton>

#define EBTNWIDTH 70
#define EBTNHEIGHT 30

Head::Head(int mWidth, int mHeight, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Head)
{
    this->setMinimumSize(mWidth,mHeight/5);
    ui->setupUi(this);
    ui->exitButton->setGeometry(mWidth-EBTNWIDTH, 0, EBTNWIDTH, EBTNHEIGHT);
    QString resolution = QString::number(mWidth)+":"+QString::number(mHeight);
    ui->labelRes->setText(resolution);
    ui->labelRes->setMinimumWidth(50);

}

Head::~Head()
{
    delete ui;
}
