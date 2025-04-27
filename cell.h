#ifndef CELL_H
#define CELL_H

#include <QWidget>

namespace Ui {
class Cell;
}

class Cell : public QWidget
{
    Q_OBJECT

public:
    explicit Cell(QSize cSize, int value, QWidget *parent = nullptr);
    ~Cell();
    int getCValue();
    void setCValue(int value);
    int getNValue();
    void setNValue(int value);

private:
    int cellValue;
    int nValue;
    Ui::Cell *ui;
};

#endif
