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

    QVector<int> shuffledValues = CellUpdater::createAndShuffleVector(possibleValues);

    QVector<QVector<Cell *>> cellGrid;
    cellGrid.resize(13);
    for(int i=0; i<13; i++){
        cellGrid[i].resize(10);
        for(int j=0; j<10; j++){
            cellGrid[i][j] = new Cell(size,shuffledValues[i*10+j]);
        }
    }
    return cellGrid;
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
