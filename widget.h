#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "craft.h"
#include "bullet.h"
#include "f35.h"
#include "bob.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //初始化场景
    void initScene();
    void go();
    void updatePos();
    //虚函数 ：重写它
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void f35Fly(); //敌机出场
    void collision();//碰撞检测
    void bombanimation(int, int);//爆炸效果


    Map map;
    Craft J20;
    QTimer timer;
//    Bullet LGM_30G;
    F35 f35Arr[F35_NUM];
    int f35Record; //敌机间隔记录
    Bob bombArr[BOMB_NUM];


};
#endif // WIDGET_H
