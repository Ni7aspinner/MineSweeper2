#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <qstackedlayout.h>
#include "entity.h"

namespace Ui {
class Cell;
}

class Cell : public QWidget
{
    Q_OBJECT

public:
    explicit Cell(QSize cSize, Entity *entity, QWidget *parent = nullptr);
    ~Cell();
    int getDamage();
    int getReward();
    void setCValue(int value);
    int getNValue();
    void setNValue(int value);
    void decrementNValue(int value);

signals:
    void entityButtonPressed(int x, int y);
    void coverButtonPressed(int x, int y);

protected:
    int nValue;
    Entity *entity;
    QStackedLayout *layout;
    Ui::Cell *ui;

protected slots:
    void hideCoverButton();
    void hideEntityButton();
};

#endif
