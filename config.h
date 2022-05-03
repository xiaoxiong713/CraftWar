#ifndef CONFIG_H
#define CONFIG_H

/**********  游戏配置数据 **********/
#define GAME_WIDTH  512  //宽度
#define GAME_HEIGHT 768  //高度
#define GAME_TITLE "飞机大战 v1.0" //标题
#define GAME_MEDIA "./media.rcc"
#define GAME_ICON ":/img/app.ico"
#define GAME_RATE 15 //定时器刷新帧率 毫秒


/**********  地图配置数据 **********/
#define MAP_BG  ":/img/img_bg_level_1.jpg" //地图图片路径
#define MAP_SCROLL_SPEED 2  //地图滚动速度


/**********  飞机配置数据 **********/
#define CRAFT ":/img/hero2.png"



/**********  子弹配置数据 **********/
#define BULLET ":/img/bullet_11.png"   //子弹图片路径
#define BULLET_SPEED 10  //子弹移动速度 5px
#define BULLET_NUM 50   //弹匣中子弹总数
#define BULLET_INTERVAL 10 //发射子弹时间间隔

/**********  敌机配置数据 **********/
#define F35_PATH  ":/img/img-plane_5.png"  //敌机资源图片
#define F35_SPEED 5 //敌机移动速度
#define F35_NUM  50  //敌机总数量
#define F35_INTERVAL  10  //敌机出场时间间隔


/**********  爆炸效果配置数据 **********/
#define BOMB_PATH  ":/img/bomb-%1.png"   //爆炸资源图片
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  7      //爆炸图片最大索引
#define BOMB_INTERVAL 10   //爆炸切图时间间隔


#define SOUND_BACKGROUND ":/img/myshoot.wav"
#define SOUND_BOMB ":/img/mybob.wav"


#endif // CONFIG_H
