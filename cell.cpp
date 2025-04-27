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

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    this->setFixedSize(cSize);
    ui->labelCValue->setFixedSize(cSize);

    ui->labelCValue->setText(QString::number(cellValue));
    ui->labelCValue->setAlignment(Qt::AlignCenter);
    ui->labelNValue->setText("10");

    QPalette labelPalette = ui->labelCValue->palette();
    labelPalette.setColor(QPalette::WindowText, Qt::black);
    ui->labelCValue->setPalette(labelPalette);
    ui->labelNValue->setPalette(labelPalette);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(1);
    layout->setContentsMargins(0, 0, 1, 1);

    layout->addWidget(ui->labelCValue);
    //layout->addWidget(ui->pushButton);
    this->setLayout(layout);
}

Cell::~Cell()
{
    delete ui;
}

int getValue(){
    return nValue;
}
void setValue(int value){
    cellValue = value;
}
