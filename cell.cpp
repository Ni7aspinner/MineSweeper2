#include "cell.h"
#include "ui_cell.h"
#include <QStackedLayout>

Cell::Cell(QSize cSize, int value, int x, int y, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell)
{
    cx=x;
    cy=y;
    cellValue=value;
    ui->setupUi(this);
    this->setAutoFillBackground(true);

    QPalette pal = this->palette();
    this->setPalette(pal);

    this->setFixedSize(cSize);
    ui->entityButton->setFixedSize(cSize);
    ui->coverButton->setFixedSize(cSize);
    ui->labelNValue->setFixedSize(cSize);

    ui->entityButton->setText(QString("+")+QString::number(cellValue));
    ui->labelNValue->setAlignment(Qt::AlignCenter);

    QPalette labelPalette = ui->labelNValue->palette();
    labelPalette.setColor(QPalette::WindowText, Qt::white);
    ui->labelNValue->setPalette(labelPalette);

    layout = new QStackedLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 1, 1);

    layout->addWidget(ui->labelNValue);
    layout->addWidget(ui->entityButton);
    layout->addWidget(ui->coverButton);
    layout->setCurrentWidget(ui->coverButton);

    connect(ui->coverButton, &QPushButton::clicked, [this](){
        emit coverButtonPressed(cy,cx);
    });
    connect(this, &Cell::coverButtonPressed, this, &Cell::hideCoverButton);

    connect(ui->entityButton, &QPushButton::clicked, [this](){
        emit entityButtonPressed(cy,cx);
    });
    connect(this, &Cell::entityButtonPressed, this, &Cell::hideEntityButton);
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
    ui->entityButton->setText(QString("+")+QString::number(value));
}
int Cell::getNValue(){
    return nValue;
}
void Cell::setNValue(int value){
    nValue = value;
    ui->labelNValue->setText(QString::number(value));
}
void Cell::decrementNValue(int value){
    nValue -= value;
    ui->labelNValue->setText(QString::number(nValue));
    if(nValue==0){ ui->labelNValue->setText("");}
}
void Cell::hideCoverButton(){
    layout->setCurrentWidget(ui->entityButton);
    if(cellValue==0){emit entityButtonPressed(cy,cx);}
}
void Cell::hideEntityButton(){
    layout->setCurrentWidget(ui->labelNValue);
}
