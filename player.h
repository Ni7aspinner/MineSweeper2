#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qprogressbar.h>

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(int mWidth, int mHeight, QWidget *parent = nullptr);

public slots:
    void getCellValue(int value);
    void getDamage(int damage);
    void getHeal();

private:
    int level;
    int energy;
    int maxEnergy;
    int scrap;
    int scrapNeeded;

    QSize progressBarSize;
    int incrementProgressBar;

    QLabel *scrapLabel;
    QHBoxLayout *hLayout;
    QWidget *leftSide;
    QWidget *rightSide;

    QHBoxLayout *upgradeLayout;
    QPushButton *upgradeButton;

    QHBoxLayout *healthLayout;
    QProgressBar *progressBar;

private slots:
    void upgradePlayer();
};

#endif
