#include "gamegrid.h"
#include "cell.h"
#include <qgridlayout.h>
#include <qpushbutton.h>

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
    cellGrid.resize(13);
    for(int i=0; i<13; i++){
        cellGrid[i].resize(10);
        for(int j=0; j<10; j++){
            cellGrid[i][j] = new Cell(QSize(mWidth/13,mHeight/10),this);
            gridLayout->addWidget(cellGrid[i][j],j,i);
        }
    }

}
