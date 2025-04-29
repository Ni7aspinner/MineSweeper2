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
            connect(cellGrid[i][j],&Cell::coverButtonPressed,[i,j,this](){
                emit coverButtonClicked(cellGrid[i][j]->getCValue());
            });
            connect(cellGrid[i][j],&Cell::entityButtonPressed,this, &GameGrid::updateNValues);
            connect(cellGrid[i][j],&Cell::entityButtonPressed,[i,j,this](){
                emit entityButtonClicked(cellGrid[i][j]->getCValue());
            });
        }
    }
}
void GameGrid::updateNValues(int x, int y){
    CellUpdater::decrementNeighboursNValue(cellGrid,x,y);
}
