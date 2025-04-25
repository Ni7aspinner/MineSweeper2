#include "cell.h"
#include "ui_cell.h"

Cell::Cell(QSize cSize, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    this->setFixedSize(cSize);
    cellValue=1;
    ui->value->setNum(cellValue);

}

Cell::~Cell()
{
    delete ui;
}
