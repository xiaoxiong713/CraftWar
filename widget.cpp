#include "widget.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QSound>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    initScene();
    go();
}

Widget::~Widget()
{
}

void Widget::initScene()
{
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    timer.setInterval(GAME_RATE);
    f35Record = 0;
    //随机数种子: 真随机
    srand((unsigned int ) time (NULL));  //按照时间1970的时间戳

}

void Widget::go()
{
//    QSound::play(SOUND_BACKGROUND);

    timer.start();
    //监听定时器发送的信号
    connect(&timer, &QTimer::timeout, [=](){
        collision();
        updatePos();//地图滚动
        f35Fly();
        update();//画家

    });
}

void Widget::updatePos()
{
    map.mapPosition();
    //    LGM_30G.Free = false;
    //    LGM_30G.updateBulletPos();
    J20.shoot(); //每隔一定的时间， 把两个弹夹里面的所有子弹变成发射状态， 注册子弹
    for(int i = 0; i <BULLET_NUM; ++i)
    {
        if(this->J20.dots[i].Free == false)
        {
            this->J20.dots[i].updateBulletPos();//处理边界问题， 越界了， 就变成 空闲状态， 等待shoot
        }


    }
    for (int j = 0; j < BULLET_NUM; ++j)
    {
        if(this->J20.dots2[j].Free == false)
        {
            this->J20.dots2[j].updateBulletPos();//处理边界问题，  越界了， 就变成 空闲状态， 等待shoot
        }
    }
    for(int q = 0; q < F35_NUM; ++ q)
    {
        if(this->f35Arr[q].F35_Free == false)
        {
            this->f35Arr[q].updateF35Position();
        }
    }

    //爆炸
    for (int k = 0; k < BOMB_MAX; ++k)
    {
        if(bombArr[k].m_Free == false)
        {
            bombArr[k].updateInfo();
        }
    }



}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this); //指定画板是当前widget
    p.drawPixmap(0, map.map1_posY, map.map1);
    p.drawPixmap(0, map.map2_posY, map.map2);
    p.drawPixmap(J20.x, J20.y, J20.J20_skin);
    //    p.drawPixmap(LGM_30G.X, LGM_30G.Y, LGM_30G.Bullet_skin);
    for (int i = 0; i < BULLET_NUM; ++i)
    {
        if(J20.dots[i].Free == false)
        {
            p.drawPixmap(J20.dots[i].X, J20.dots[i].Y, J20.dots[i].Bullet_skin);

        }

    }
    for (int o = 0; o < BULLET_NUM; ++o)
    {
        if( J20.dots2[o].Free == false)
        {
            p.drawPixmap(J20.dots2[o].X, J20.dots2[o].Y, J20.dots2[o].Bullet_skin);

        }
    }
    for(int j = 0; j < F35_NUM; ++ j)
    {
        if(f35Arr[j].F35_Free == false)
        {
            p.drawPixmap(f35Arr[j].F35_X, f35Arr[j].F35_Y, f35Arr[j].F35_skin);
        }
    }


    //爆炸
    for (int k = 0; k < BOMB_MAX; ++k)
    {
        if(bombArr[k].m_Free == false)
        {
            p.drawPixmap(bombArr[k].m_X, bombArr[k].m_Y,
                         bombArr[k].m_pixArr[bombArr[k].m_index]);
        }
    }




}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int a = event->x() - J20.J20_skin.width() * 0.5;
    int b = event->y() - J20.J20_skin.height() *0.5;
    //边界检测
    if(a <= 0 )
    {
        a = 0;
    }
    if(a >= GAME_WIDTH - J20.rect.width())
    {
        a = GAME_WIDTH - J20.rect.width();
    }
    if(b <= 0)
    {
        b = 0;
    }
    if(b >= GAME_HEIGHT - J20.rect.height())
    {
        b = GAME_HEIGHT - J20.rect.height();
    }

    J20.move(a, b);
}

void Widget::f35Fly()
{
    //敌机出场
    this->f35Record ++;
    if(this->f35Record < F35_INTERVAL)
    {
        //未达到出场的间隔时间
        return;
    }

    this->f35Record = 0;
    for(int i = 0; i < F35_NUM; ++ i)
    {
        if(this->f35Arr[i].F35_Free)
        {
            this->f35Arr[i].F35_Free = false;
            //新出场的敌机 的位置
            this->f35Arr[i].F35_X =  rand() % (GAME_WIDTH - f35Arr[i].F35_skin.width());
            this->f35Arr[i].F35_Y = - this->f35Arr[i].F35_skin.height();//边框外部出场
            break;
        }
    }
}

void Widget::collision()
{
    for(int  i = 0; i < BULLET_NUM * 2;  ++ i)
    {
        if(i < BULLET_NUM)
        {
            if(J20.dots[i].Free)
            {
                continue;
            }

            for (int j = 0; j < F35_NUM; ++j)
            {

                if(f35Arr[j].F35_Free)
                {
                    continue;
                }

                if(f35Arr[j].F35_Rect.intersects(J20.dots[i].Rect))
                {
                    f35Arr[j].F35_Free = true;
                    J20.dots[i].Free = true;
                    this->bombanimation(f35Arr[j].F35_X, f35Arr[j].F35_Y);
                    break;
                }

            }

        }else if(i >= BULLET_NUM)
        {
            int tem = i - BULLET_NUM;
            if(J20.dots2[tem].Free)
            {
                continue;
            }

            for (int j = 0; j < F35_NUM; ++j)
            {

                if(f35Arr[j].F35_Free)
                {
                    continue;
                }

                if(f35Arr[j].F35_Rect.intersects(J20.dots2[tem].Rect))
                {
                    f35Arr[j].F35_Free = true;
                    J20.dots2[tem].Free = true;
                    this->bombanimation(f35Arr[j].F35_X, f35Arr[j].F35_Y);
                    break;
                }

            }


        }
    }
}

void Widget::bombanimation(int x, int y)
{
    for (int i = 0; i < BOMB_NUM; ++i)
    {
        if(bombArr[i].m_Free)
        {
            bombArr[i].m_Free = false;
            bombArr[i].m_X = x;
            bombArr[i].m_Y = y;
//            QSound::play(SOUND_BOMB);
            break;
        }
    }
}





















