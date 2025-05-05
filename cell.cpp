#include "cell.h"
#include "ui_cell.h"
#include <QStackedLayout>
#include "entity.h"

Cell::Cell(QSize cSize, Entity *entity, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell)
    , entity(entity)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);

    QPalette pal = this->palette();
    this->setPalette(pal);

    this->setFixedSize(cSize);

    QSize imageSize = QSize(cSize.width(),6*cSize.height()/10);
    QSize valueSize = QSize(cSize.width(),4*cSize.height()/10);

    ui->entityButton->setFixedSize(cSize);
    ui->entityButton->setText("");
    ui->coverButton->setFixedSize(cSize);
    ui->coverButton->setText("");
    ui->labelNValue->setFixedSize(cSize);

    QVBoxLayout* coverLayout = new QVBoxLayout();
    coverLayout->setSpacing(0);
    coverLayout->setContentsMargins(0, 0, 0, 0);
    image1Label = new QLabel();
    image1Label->setAlignment(Qt::AlignCenter);
    image1Label->setFixedSize(imageSize);
    coverLayout->addWidget(image1Label);
    if(entity->hidden)image1Label->hide();
    damageLabel = new QLabel();
    damageLabel->setFixedSize(valueSize);
    coverLayout->addWidget(damageLabel);
    damageLabel->setAlignment(Qt::AlignCenter);
    if(entity->hidden) damageLabel->hide();
    ui->coverButton->setLayout(coverLayout);

    QVBoxLayout* entityLayout = new QVBoxLayout();
    entityLayout->setSpacing(0);
    entityLayout->setContentsMargins(0, 0, 0, 0);
    image2Label = new QLabel();
    image2Label->setFixedSize(imageSize);
    image2Label->setAlignment(Qt::AlignCenter);
    entityLayout->addWidget(image2Label);
    rewardLabel= new QLabel();
    rewardLabel->setFixedSize(valueSize);
    rewardLabel->setAlignment(Qt::AlignCenter);
    entityLayout->addWidget(rewardLabel);
    ui->entityButton->setLayout(entityLayout);

    if(!entity->bg.isNull()){
        entity->bg = entity->bg.scaled(image1Label->size()/2, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        image1Label->setPixmap(entity->bg);
        image2Label->setPixmap(entity->bg);
    }
    else{
        image1Label->setText(entity->name);
        if(entity->damage!=0){
            damageLabel = new QLabel(QString::number(entity->damage));
        }
        else{
            damageLabel->setText("");
        }
        image2Label->setText(entity->name);
        if(entity->reward!=0){
            rewardLabel = new QLabel("+"+QString::number(entity->reward));
        }
        else{
            rewardLabel->setText("");
        }
    }
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

    connect(ui->coverButton, &QPushButton::clicked, [this, entity](){
        emit coverButtonPressed(entity->x,entity->y);
    });
    connect(this, &Cell::coverButtonPressed, this, &Cell::hideCoverButton);

    connect(ui->entityButton, &QPushButton::clicked, [this, entity](){
        emit entityButtonPressed(entity->x,entity->y);
    });
    connect(this, &Cell::entityButtonPressed, this, &Cell::hideEntityButton);
    this->setLayout(layout);

}

Cell::~Cell()
{
    delete ui;
}

int Cell::getDamage(){
    return entity->damage;
}
int Cell::getReward(){
    return entity->reward;
}
void Cell::setCValue(int value){
    entity->damage = value;
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
    if(entity->id==0){emit entityButtonPressed(entity->x,entity->y);}
    if(entity->transform!=0 && entity->reward!=0) updateCell();
    else layout->setCurrentWidget(ui->entityButton);
}
void Cell::hideEntityButton(){
    if(entity->transform!=0) updateCell();
    else layout->setCurrentWidget(ui->labelNValue);
}
void Cell::updateCell(){
    int tempX = entity->x;
    int tempY = entity->y;
    int tempId = entity->transform;
    entity = new Entity(tempId,tempX,tempY);
    image1Label->setText(entity->name);
    if(entity->damage!=0){
        damageLabel = new QLabel(QString::number(entity->damage));
    }
    else{
        damageLabel->setText("");
    }
    image2Label->setText(entity->name);
    if(entity->reward!=0){
        rewardLabel = new QLabel("+"+QString::number(entity->reward));
    }
    else{
        rewardLabel->setText("");
    }
    image1Label->show();
    damageLabel->show();
}
