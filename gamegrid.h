#ifndef GAMEGRID_H
#define GAMEGRID_H

#include <QWidget>

class GameGrid : public QWidget
{
    Q_OBJECT

public:
    explicit GameGrid(int mWidth, int mHeight, QWidget *parent = nullptr);
};

#endif
