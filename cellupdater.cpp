#include "cellupdater.h"
#include "cell.h"
#include "entity.h"
#include <random>


QVector<QVector<Cell *>> CellUpdater::assignValues(QSize size){
    int possibleValues[20][2] = {
        {13,1},{12,2},{10,3},
        {8,4},{8,5},{5,6},
        {4,7},{5,8},{2,9},
        {1,10},{1,11},{1,13},
        {2,14},{1,15},{9,16},
        {2,18},{4,19},{1,25},
        {1,26},{1,27}};

    QVector<Entity *> shuffledEntities = createAndShuffleVector(possibleValues);

    QVector<QVector<Cell *>> cellGrid;
    cellGrid.resize(13);
    for(int i=0; i<13; i++){
        cellGrid[i].resize(10);
        for(int j=0; j<10; j++){
            cellGrid[i][j] = new Cell(size,shuffledEntities[i*10+j]);
        }
    }
    return calculateAllNValues(cellGrid);
}
QVector<Entity *> CellUpdater::createAndShuffleVector(int possibleValues[14][2]){
    QVector<int> vector(130,0);
    int n=0;
    for(int i=0; i<20; i++){
        for(int j=0; j<possibleValues[i][0]; j++){
            vector[n]=possibleValues[i][1];
            n++;
        }
    }
    std::shuffle(vector.begin(),vector.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    QVector<Entity *> entities(130);
    n=0;
    for(int i=0; i<13; i++){
        for(int j=0; j<10; j++){
            entities[n] = new Entity(vector[n],i,j);
        n++;
        }
    }
    return entities;
}
void CellUpdater::decrementNeighboursNValue(QVector<QVector<Cell *>> cellGrid, int x, int y){
    int value = cellGrid[x][y]->getDamage();
    if(x==0){
        if(y==0){
            cellGrid[x][y+1]->decrementNValue(value);
            cellGrid[x+1][y+1]->decrementNValue(value);
            cellGrid[x+1][y]->decrementNValue(value);
        }
        else if(y==9){
            cellGrid[x][y-1]->decrementNValue(value);
            cellGrid[x+1][y]->decrementNValue(value);
            cellGrid[x+1][y-1]->decrementNValue(value);
        }
        else{
            cellGrid[x][y+1]->decrementNValue(value);
            cellGrid[x][y-1]->decrementNValue(value);
            cellGrid[x+1][y+1]->decrementNValue(value);
            cellGrid[x+1][y]->decrementNValue(value);
            cellGrid[x+1][y-1]->decrementNValue(value);
        }
    }
    else if(x==12){
        if(y==0){
            cellGrid[x][y+1]->decrementNValue(value);
            cellGrid[x-1][y+1]->decrementNValue(value);
            cellGrid[x-1][y]->decrementNValue(value);
        }
        else if(y==9){
            cellGrid[x][y-1]->decrementNValue(value);
            cellGrid[x-1][y]->decrementNValue(value);
            cellGrid[x-1][y-1]->decrementNValue(value);
        }
        else{
            cellGrid[x][y+1]->decrementNValue(value);
            cellGrid[x][y-1]->decrementNValue(value);
            cellGrid[x-1][y+1]->decrementNValue(value);
            cellGrid[x-1][y]->decrementNValue(value);
            cellGrid[x-1][y-1]->decrementNValue(value);
        }
    }
    else{
        if(y==0){
            cellGrid[x][y+1]->decrementNValue(value);
            cellGrid[x-1][y+1]->decrementNValue(value);
            cellGrid[x-1][y]->decrementNValue(value);
            cellGrid[x+1][y+1]->decrementNValue(value);
            cellGrid[x+1][y]->decrementNValue(value);
        }
        else if(y==9){
            cellGrid[x][y-1]->decrementNValue(value);
            cellGrid[x-1][y]->decrementNValue(value);
            cellGrid[x-1][y-1]->decrementNValue(value);
            cellGrid[x+1][y]->decrementNValue(value);
            cellGrid[x+1][y-1]->decrementNValue(value);
        }
        else{
            cellGrid[x][y+1]->decrementNValue(value);
            cellGrid[x][y-1]->decrementNValue(value);
            cellGrid[x-1][y+1]->decrementNValue(value);
            cellGrid[x-1][y]->decrementNValue(value);
            cellGrid[x-1][y-1]->decrementNValue(value);
            cellGrid[x+1][y+1]->decrementNValue(value);
            cellGrid[x+1][y]->decrementNValue(value);
            cellGrid[x+1][y-1]->decrementNValue(value);
        }
    }
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
            sum+=cellGrid[x][y+1]->getDamage();
            sum+=cellGrid[x+1][y+1]->getDamage();
            sum+=cellGrid[x+1][y]->getDamage();
        }
        else if(y==9){
            sum+=cellGrid[x][y-1]->getDamage();
            sum+=cellGrid[x+1][y]->getDamage();
            sum+=cellGrid[x+1][y-1]->getDamage();
        }
        else{
            sum+=cellGrid[x][y+1]->getDamage();
            sum+=cellGrid[x][y-1]->getDamage();
            sum+=cellGrid[x+1][y+1]->getDamage();
            sum+=cellGrid[x+1][y]->getDamage();
            sum+=cellGrid[x+1][y-1]->getDamage();
        }
    }
    else if(x==12){
        if(y==0){
            sum+=cellGrid[x][y+1]->getDamage();
            sum+=cellGrid[x-1][y+1]->getDamage();
            sum+=cellGrid[x-1][y]->getDamage();
        }
        else if(y==9){
            sum+=cellGrid[x][y-1]->getDamage();
            sum+=cellGrid[x-1][y]->getDamage();
            sum+=cellGrid[x-1][y-1]->getDamage();
        }
        else{
            sum+=cellGrid[x][y+1]->getDamage();
            sum+=cellGrid[x][y-1]->getDamage();
            sum+=cellGrid[x-1][y+1]->getDamage();
            sum+=cellGrid[x-1][y]->getDamage();
            sum+=cellGrid[x-1][y-1]->getDamage();
        }
    }
    else{
        if(y==0){
            sum+=cellGrid[x][y+1]->getDamage();
            sum+=cellGrid[x-1][y+1]->getDamage();
            sum+=cellGrid[x-1][y]->getDamage();
            sum+=cellGrid[x+1][y+1]->getDamage();
            sum+=cellGrid[x+1][y]->getDamage();
        }
        else if(y==9){
            sum+=cellGrid[x][y-1]->getDamage();
            sum+=cellGrid[x-1][y]->getDamage();
            sum+=cellGrid[x-1][y-1]->getDamage();
            sum+=cellGrid[x+1][y]->getDamage();
            sum+=cellGrid[x+1][y-1]->getDamage();
        }
        else{
            sum+=cellGrid[x][y+1]->getDamage();
            sum+=cellGrid[x][y-1]->getDamage();
            sum+=cellGrid[x-1][y+1]->getDamage();
            sum+=cellGrid[x-1][y]->getDamage();
            sum+=cellGrid[x-1][y-1]->getDamage();
            sum+=cellGrid[x+1][y+1]->getDamage();
            sum+=cellGrid[x+1][y]->getDamage();
            sum+=cellGrid[x+1][y-1]->getDamage();
        }
    }
    return sum;
}

