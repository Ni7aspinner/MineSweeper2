#include "gamegrid.h"
#include "cell.h"
#include <qgridlayout.h>
#include <qpushbutton.h>
#include "cellupdater.h"

GameGrid::GameGrid(int mWidth, int mHeight, QWidget *parent) {
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::darkGray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setFixedSize(mWidth,mHeight);

    mWidth-=14;
    mHeight-=11;

    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(1);
    gridLayout->setContentsMargins(1, 1, 1, 1);
    cellGrid = CellUpdater::assignValues(QSize(mWidth/13,mHeight/10));
    for(int i=0; i<13; i++){
        for(int j=0; j<10; j++){
            gridLayout->addWidget(cellGrid[i][j],j,i);
            connect(cellGrid[i][j],&Cell::coverButtonPressed,this,[this,i,j](){
                emit coverButtonClicked(cellGrid[i][j]->getDamage());
            });
            connect(cellGrid[i][j],&Cell::entityButtonPressed,this, &GameGrid::updateNValues);
            connect(cellGrid[i][j],&Cell::healPlayer,this, &GameGrid::healPlayer);
            connect(cellGrid[i][j],&Cell::entityButtonPressed,this,[this,i,j](){
                emit entityButtonClicked(cellGrid[i][j]->getReward());
            });
            connect(cellGrid[i][j],&Cell::activeScanner, this, [this,i,j](bool random){
                CellUpdater::activeScanner(cellGrid,i,j,random);
            });
        }
    }
}
void GameGrid::updateNValues(int x, int y){
    CellUpdater::decrementNeighboursNValue(cellGrid,x,y);
}
