#include "player.h"
#include <QLabel>
#include <QPushButton>
#include <qboxlayout.h>
#include <qprogressbar.h>

Player::Player(int mWidth, int mHeight, QWidget *parent)
    : QWidget(parent)
{
    this->setAutoFillBackground(true);
    this->setFixedSize(mWidth,mHeight);

    level=0;
    maxEnergy = 5;
    energy=5;
    scrap=0;
    scrapNeeded=3;

    hLayout = new QHBoxLayout(this);

    hLayout->setSpacing(0);
    hLayout->setContentsMargins(0, 0, 1, 1);

    int lWidth = 7*mWidth/10;
    leftSide = new QWidget();
    leftSide->setFixedSize(lWidth,mHeight);
    hLayout->addWidget(leftSide);

    healthLayout = new QHBoxLayout();
    healthLayout->setSpacing(5);
    healthLayout->setContentsMargins(0, 0, 0, 0);

    leftSide->setLayout(healthLayout);
    healthLayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    progressBarSize = QSize(lWidth/3,2*mHeight/3);
    incrementProgressBar = (lWidth/30);

    progressBar = new QProgressBar();
    progressBar->setObjectName("progressBar");
    progressBar->setMinimum(0);
    progressBar->setMaximum(5);
    progressBar->setFixedSize(progressBarSize);
    progressBar->setFormat("%v/%m");
    progressBar->setValue(5);

    healthLayout->addWidget(progressBar);

    int rWidth = 3*mWidth/10;
    rightSide = new QWidget();
    rightSide->setFixedSize(rWidth,mHeight);
    hLayout->addWidget(rightSide);

    upgradeLayout = new QHBoxLayout();
    upgradeLayout->setSpacing(5);
    upgradeLayout->setContentsMargins(0, 0, 0, 0);
    upgradeLayout->setAlignment(Qt::AlignCenter);
    rightSide->setLayout(upgradeLayout);

    scrapLabel = new QLabel("0/3");
    scrapLabel->setObjectName("scrapLabel");
    scrapLabel->setFixedSize(rWidth/2-10,mHeight-mHeight/10);
    scrapLabel->setAlignment(Qt::AlignRight| Qt::AlignVCenter);
    upgradeLayout->addWidget(scrapLabel);

    upgradeButton = new QPushButton("UPGRADE");
    upgradeButton->setObjectName("upgradeButton");
    upgradeButton->setFixedSize(rWidth/2,mHeight-mHeight/10);
    upgradeLayout->addWidget(upgradeButton);
    connect(upgradeButton, &QPushButton::clicked, this, &Player::upgradePlayer);

}
void Player::upgradePlayer(){
    if(scrap>=scrapNeeded){
        scrap-=scrapNeeded;
        level++;
        if(level%2==0){
            scrapNeeded+=2;
            maxEnergy++;
            int temp = progressBarSize.width();
            progressBarSize.setWidth(temp+incrementProgressBar);
            progressBar->setFixedSize(progressBarSize);
        }
        else{
            scrapNeeded++;
        }
        energy=maxEnergy;
        progressBar->setMaximum(maxEnergy);
        progressBar->setValue(energy);
        scrapLabel->setText(QString::number(scrap)+"/"+QString::number(scrapNeeded));
    }
}
void Player::getCellValue(int value){
    scrap+=value;
    scrapLabel->setText(QString::number(scrap)+"/"+QString::number(scrapNeeded));
}
void Player::getDamage(int damage){
    if(damage<=energy){
        energy-=damage;
        progressBar->setValue(energy);
    }
    else {
        energy=0;
        progressBar->setValue(energy);
    }
}


