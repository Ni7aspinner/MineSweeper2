#include "cellupdater.h"
#include "cell.h"
#include <random>

QVector<QVector<Cell *>> CellUpdater::assignValues(QSize size){
    int possibleValues[14][2] = {
        {14,1},{12,2},{10,3},
        {8,4},{11,5},{5,6},
        {4,7},{5,8},{2,9},
        {1,10},{1,11},
        {9,100}, {9,-1}};

    QVector<int> shuffledValues = createAndShuffleVector(possibleValues);

    QVector<QVector<Cell *>> cellGrid;
    cellGrid.resize(13);
    for(int i=0; i<13; i++){
        cellGrid[i].resize(10);
        for(int j=0; j<10; j++){
            cellGrid[i][j] = new Cell(size,shuffledValues[i*10+j]);
        }
    }
    return calculateAllNValues(cellGrid);
}
QVector<int> CellUpdater::createAndShuffleVector(int possibleValues[14][2]){
    QVector<int> vector(130,0);
    int n=0;
    for(int i=0; i<14; i++){
        for(int j=0; j<possibleValues[i][0]; j++){
            vector[n]=possibleValues[i][1];
            n++;
        }
    }
    std::shuffle(vector.begin(),vector.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    return vector;
}
QVector<QVector<Cell *>> CellUpdater::decrementNeighboursNValue(QVector<QVector<Cell *>> cellGrid, int x, int y){
    return cellGrid;
}
QVector<QVector<Cell *>> CellUpdater::calculateAllNValues(QVector<QVector<Cell *>> cellGrid){
    for(int i=0; i<13; i++){
        for(int j=0; j<10; j++){
            cellGrid[i][j]->setNValue(calculateNValue(cellGrid,i,j));
        }
    }
    return cellGrid;
}
int CellUpdater::calculateNValue(QVector<QVector<Cell *>> cellGrid, int x, int y){
    int sum=0;
    if(x==0){
        if(y==0){
            sum+=cellGrid[x][y+1]->getCValue();
            sum+=cellGrid[x+1][y+1]->getCValue();
            sum+=cellGrid[x+1][y]->getCValue();
        }
        else if(y==9){
            sum+=cellGrid[x][y-1]->getCValue();
            sum+=cellGrid[x+1][y]->getCValue();
            sum+=cellGrid[x+1][y-1]->getCValue();
        }
        else{
            sum+=cellGrid[x][y+1]->getCValue();
            sum+=cellGrid[x][y-1]->getCValue();
            sum+=cellGrid[x+1][y+1]->getCValue();
            sum+=cellGrid[x+1][y]->getCValue();
            sum+=cellGrid[x+1][y-1]->getCValue();
        }
    }
    else if(x==12){
        if(y==0){
            sum+=cellGrid[x][y+1]->getCValue();
            sum+=cellGrid[x-1][y+1]->getCValue();
            sum+=cellGrid[x-1][y]->getCValue();
        }
        else if(y==9){
            sum+=cellGrid[x][y-1]->getCValue();
            sum+=cellGrid[x-1][y]->getCValue();
            sum+=cellGrid[x-1][y-1]->getCValue();
        }
        else{
            sum+=cellGrid[x][y+1]->getCValue();
            sum+=cellGrid[x][y-1]->getCValue();
            sum+=cellGrid[x-1][y+1]->getCValue();
            sum+=cellGrid[x-1][y]->getCValue();
            sum+=cellGrid[x-1][y-1]->getCValue();
        }
    }
    else{
        if(y==0){
            sum+=cellGrid[x][y+1]->getCValue();
            sum+=cellGrid[x-1][y+1]->getCValue();
            sum+=cellGrid[x-1][y]->getCValue();
            sum+=cellGrid[x+1][y+1]->getCValue();
            sum+=cellGrid[x+1][y]->getCValue();
        }
        else if(y==9){
            sum+=cellGrid[x][y-1]->getCValue();
            sum+=cellGrid[x-1][y]->getCValue();
            sum+=cellGrid[x-1][y-1]->getCValue();
            sum+=cellGrid[x+1][y]->getCValue();
            sum+=cellGrid[x+1][y-1]->getCValue();
        }
        else{
            sum+=cellGrid[x][y+1]->getCValue();
            sum+=cellGrid[x][y-1]->getCValue();
            sum+=cellGrid[x-1][y+1]->getCValue();
            sum+=cellGrid[x-1][y]->getCValue();
            sum+=cellGrid[x-1][y-1]->getCValue();
            sum+=cellGrid[x+1][y+1]->getCValue();
            sum+=cellGrid[x+1][y]->getCValue();
            sum+=cellGrid[x+1][y-1]->getCValue();
        }
    }
    return sum;
}

