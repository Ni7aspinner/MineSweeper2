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
    explicit Cell(QSize cSize, QWidget *parent = nullptr);
    ~Cell();

private:
    int cellValue;
    int nValue;
    Ui::Cell *ui;
};

#endif // CELL_H
