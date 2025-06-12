#include "mainwindow.h"
#include "player.h"
#include "ui_mainwindow.h"
#include "head.h"
#include <QTimer>
#include <QPainter>
#include "gamegrid.h"
#include <QPushButton>
#include <random>

#define EBTNWIDTH 40
#define EBTNHEIGHT 30

Head *head;
GameGrid *game;

MainWindow::MainWindow(int mWidth, int mHeight, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(mWidth,mHeight);

    ui->setupUi(this);
    ui->labelRes->setFixedSize(80,30);
    QString resolution = QString::number(this->size().width())+":"+QString::number(this->size().height());
    ui->labelRes->setText(resolution);
    ui->labelRes->setGeometry(0,0,50,15);
    ui->exitButton->setGeometry(mWidth-EBTNWIDTH, 0, EBTNWIDTH, EBTNHEIGHT);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::darkGray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    int vSize = (mWidth-mHeight)/2;
    int pixW = mHeight%13;
    mWidth = mHeight-pixW+14;

    animateBg();

    QWidget *container = new QWidget(this);
    container->setGeometry(vSize,0,mWidth,mHeight);
    QVBoxLayout *mainLayout = new QVBoxLayout(container);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    head = new Head(mWidth,mHeight/10);

    int pixH = (19*mHeight/24)%10;
    game = new GameGrid(mWidth,(19*mHeight/24)-pixH+11);

    player = new Player(mWidth,(mHeight - head->size().height() - game->size().height()));

    mainLayout->addWidget(head);
    mainLayout->addWidget(game);
    mainLayout->addWidget(player);

    connect(game,&GameGrid::entityButtonClicked,player,&Player::getCellValue);
    connect(game,&GameGrid::coverButtonClicked,player,&Player::getDamage);
    connect(game,&GameGrid::healPlayer,player,&Player::getHeal);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animateBg(){
    std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distX(1, 8);
    QString bgPath = ":/images/Backgrounds/Bg" +QString::number(distX(engine));

    bgPixMap = QPixmap(bgPath);
    bgOffset = QPoint(0, 0);

    bgTimer = new QTimer(this);
    connect(bgTimer, &QTimer::timeout, this, [this]() {
        bgOffset -= QPoint(1, 1);
        update();
    });
    bgTimer->start(50);
}
void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if(!bgPixMap.isNull()){

        int startX = bgOffset.x() % bgPixMap.width();
        int startY = bgOffset.y() % bgPixMap.height();

        for(int x=startX; x<this->width(); x+=bgPixMap.width()) {
            for(int y=startY; y<this->height(); y+=bgPixMap.height()) {
                painter.drawPixmap(x, y, bgPixMap);
            }
        }
    }
    QWidget::paintEvent(event);
}

