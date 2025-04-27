#include "cell.h"
#include "ui_cell.h"
#include <qboxlayout.h>

int cellValue;
int nValue;

Cell::Cell(QSize cSize, int value, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell)
{
    cellValue=value;
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    //ui->labelCValue->hide();

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    this->setFixedSize(cSize);
    ui->labelCValue->setFixedSize(cSize);
    ui->labelNValue->setFixedSize(cSize);

    ui->labelCValue->setText(QString::number(cellValue));
    ui->labelCValue->setAlignment(Qt::AlignCenter);
    ui->labelNValue->setAlignment(Qt::AlignCenter);

    QPalette labelPalette = ui->labelCValue->palette();
    labelPalette.setColor(QPalette::WindowText, Qt::red);
    ui->labelCValue->setPalette(labelPalette);
    labelPalette.setColor(QPalette::WindowText, Qt::black);
    ui->labelNValue->setPalette(labelPalette);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 1, 1);

    layout->addWidget(ui->labelNValue);
    //layout->addWidget(ui->pushButton);
    this->setLayout(layout);
}

Cell::~Cell()
{
    delete ui;
}

int Cell::getCValue(){
    return cellValue;
}
void Cell::setCValue(int value){
    cellValue = value;
    ui->labelCValue->setText(QString::number(value));
}
int Cell::getNValue(){
    return nValue;
}
void Cell::setNValue(int value){
    nValue = value;
    ui->labelNValue->setText(QString::number(value));
}
