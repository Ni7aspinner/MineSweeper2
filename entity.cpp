#include "entity.h"

Entity::Entity(int id, int coordinateX, int coordinateY): id(id), x(coordinateX), y(coordinateY){
    if(id>0 && id<11) {
        damage=id;
        reward=id;
    }
    switch(id){
        case 1:
            name = QString("Enemy1");
            bg = QPixmap(":/images/Enemies/enemy1");
            break;
        case 2:
            name = QString("Enemy2");
            bg = QPixmap(":/images/Enemies/enemy2");
            break;
        case 3:
            name = QString("Enemy3");
            bg = QPixmap(":/images/Enemies/enemy3");
            break;
        case 4:
            name = QString("Enemy4");
            bg = QPixmap(":/images/Enemies/enemy4");
            break;
        case 5:
            name = QString("Enemy5");
            bg = QPixmap(":/images/Enemies/enemy5");
            break;
        case 6:
            name = QString("Enemy6");
            bg = QPixmap(":/images/Enemies/enemy6");
            break;
        case 7:
            name = QString("Enemy7");
            bg = QPixmap(":/images/Enemies/enemy7");//black background
            break;
        case 8:
            name = QString("Enemy8");
            bg = QPixmap(":/images/Enemies/enemy8");
            break;
        case 9:
            name = QString("Enemy9");
            bg = QPixmap(":/images/Enemies/enemy9");
            transform=20;
            break;
        case 10:
            name = QString("Bomber");
            damage=id;
            reward=id;
            transform = 22;
            break;
        case 11:
            name = QString("Chest");
            bg = QPixmap(":/images/Items/chest");
            damage=11;// has black background
            transform = 12;
            break;
        case 12:
            name = QString("Mimic");
            bg = QPixmap(":/images/Enemies/mimic");
            reward=11;
            break;
        case 13:
            name = QString("King");
            bg = QPixmap(":/images/Enemies/king");
            damage=5;
            reward=5;
            transform = 23;
            break;
        case 14:
            name = QString("Mute");
            bg = QPixmap(":/images/Enemies/mute");
            damage=5;
            reward=5;
            //custom logic;
            break;
        case 15:
            name = QString("Mage");
            damage=1;
            reward=1;
            transform = 24;
            break;
        case 16:
            name = QString("Bomb");
            damage=100;
            reward=0;
            transform = 17;
            break;
        case 17:
            name = QString("DefusedBomb");
            damage=0;
            reward=3;
            break;
        case 18:
            name = QString("Chest");
            bg = QPixmap(":/images/Items/chest");
            damage=0;
            reward=0;
            transform=20;
            break;
        case 19:
            name = QString("Chest");
            bg = QPixmap(":/images/Items/chest");
            damage=0;
            reward=0;
            transform=21;
            break;
        case 20:
            name = QString("Health");
            bg = QPixmap(":/images/Items/health");
            damage=0;
            reward=0;
            //custom
            break;
        case 21:
            name = QString("Money");
            bg = QPixmap(":/images/Items/scrap");
            damage=0;
            reward=5;
            //custom
            break;
        case 22:
            name = QString("AntiBomb");
            break;
        case 23:
            name = QString("AntiE1");
            break;
        case 24:
            name = QString("AntiE5/E8");
            break;
        case 25:
            name = QString("Boss");
            bg = QPixmap(":/images/enemies/boss");
            damage=13;
            reward=13;
            hidden=false;
            break;
        case 26:
            name = QString("Scan");
            bg = QPixmap(":/images/Items/scanner");
            hidden=false;
            break;
        case 27:
            name = QString("HiddenScan");
            bg = QPixmap(":/images/Items/scanner");
            break;
    }
}
