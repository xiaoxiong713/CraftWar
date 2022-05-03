#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>

class Bullet
{
public:
    Bullet();


    //更新子弹坐标
    void updateBulletPos();

public:
    //子弹资源对象
    QPixmap Bullet_skin;
    //子弹坐标
    int X;
    int Y;
    //子弹移动速度
    int Speed;
    //子弹是否闲置
    bool Free;
    //子弹的矩形边框（用于碰撞检测）
    QRect Rect;
};

#endif // BULLET_H
