#ifndef ENTITY_H
#define ENTITY_H

#include <qobject.h>
#include <qpixmap.h>
class Entity
{
public:
    Entity(int id, int x, int y);
    int id;
    int x;
    int y;
    QPixmap bg;
    QString name;
    int reward=0;
    int damage=0;
    bool hidden=true;
    int transform = 0;
};

#endif // ENTITY_H
