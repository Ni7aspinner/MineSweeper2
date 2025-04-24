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
    explicit Cell(QWidget *parent = nullptr);
    ~Cell();

private:
    Ui::Cell *ui;
};

#endif // CELL_H
