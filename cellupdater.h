#ifndef CELLUPDATER_H
#define CELLUPDATER_H

#include "cell.h"


class CellUpdater
{
public:
    static QVector<QVector<Cell *>> assignValues(QSize size);

private:
    static QVector<int> createAndShuffleVector(int possibleValues[14][2]);

};

#endif
