#ifndef CRAFT_H
#define CRAFT_H
#include <QPixmap>
#include <QRect>
#include <bullet.h>
#include "config.h"
class Craft
{
public:
    Craft();
    void shoot();
    void move(int, int);


    QPixmap J20_skin;
    int x;
    int y;
    QRect rect;
    Bullet dots[BULLET_NUM];//弹夹
    Bullet dots2[BULLET_NUM];//双弹夹
    int record; //发射间隔记录

};

#endif // CRAFT_H
