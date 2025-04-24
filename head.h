#ifndef HEAD_H
#define HEAD_H

#include <QWidget>

namespace Ui {
class Head;
}

class Head : public QWidget
{
    Q_OBJECT

public:
    explicit Head(int mWidth, int mHeight, QWidget *parent = nullptr);
    ~Head();

private:
    Ui::Head *ui;
};

#endif
