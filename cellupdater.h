#ifndef CELLUPDATER_H
#define CELLUPDATER_H

#include "cell.h"


class CellUpdater
{
public:
    static QVector<QVector<Cell *>> assignValues(QSize size);
    static void decrementNeighboursNValue(QVector<QVector<Cell *>> cellGrid, int x, int y);
    static void activeScanner(QVector<QVector<Cell *>> cellGrid, int x, int y, bool random);

private:
    static void setNeighboursVisible(QVector<QVector<Cell *>> cellGrid, int x, int y);
    static QVector<Entity *> createAndShuffleVector(int possibleValues[14][2]);
    static QVector<QVector<Cell *>> calculateAllNValues(QVector<QVector<Cell *>> cellGrid);
    static int calculateNValue(QVector<QVector<Cell *>> cellGrid, int x, int y);
};

#endif
