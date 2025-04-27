#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "cell.h"
#include <QWidget>
#include <qgridlayout.h>

class GameGrid : public QWidget
{
    Q_OBJECT

public:
    explicit GameGrid(int mWidth, int mHeight, QWidget *parent = nullptr);

private:
    QVector<QVector<Cell *>> cellGrid;
    QGridLayout *gridLayout;

private slots:
    void updateNValues(int x, int y);
};

#endif
