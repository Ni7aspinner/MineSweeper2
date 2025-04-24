#include "gamegrid.h"
#include "cell.h"

GameGrid::GameGrid(int mWidth, int mHeight, QWidget *parent) {
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setFixedSize(mWidth,mHeight);
    this->setBackgroundRole(QPalette::Window);

    QVector<QVector<Cell>> cellGrid[13][10];


}
