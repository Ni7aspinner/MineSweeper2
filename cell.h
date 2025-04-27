#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <qstackedlayout.h>

namespace Ui {
class Cell;
}

class Cell : public QWidget
{
    Q_OBJECT

public:
    explicit Cell(QSize cSize, int value, int x, int y, QWidget *parent = nullptr);
    ~Cell();
    int getCValue();
    void setCValue(int value);
    int getNValue();
    void setNValue(int value);
    void decrementNValue(int value);

signals:
    void entityButtonPressed(int x, int y);
    void coverButtonPressed(int x, int y);

private:
    int cellValue;
    int nValue;
    int cx;
    int cy;
    QStackedLayout *layout;
    Ui::Cell *ui;

private slots:
    void hideCoverButton();
    void hideEntityButton();
};

#endif
