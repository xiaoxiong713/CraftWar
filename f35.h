#ifndef F35_H
#define F35_H
#include <QPixmap>
#include "config.h"
class F35
{
public:
    F35();

    //更新坐标
    void updateF35Position();
    //敌机资源对象
    QPixmap F35_skin;

    //位置
    int F35_X;
    int F35_Y;

    //敌机的矩形边框（碰撞检测）
    QRect F35_Rect;

    //状态
    bool F35_Free;

    //速度
    int F35_Speed;


};

#endif // F35_H
