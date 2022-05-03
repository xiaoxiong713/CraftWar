#include "map.h"
#include "config.h"
Map::Map()
{
    //加载背景 等初始化
    map1.load(MAP_BG);
    map2.load(MAP_BG);

    map1_posY = -GAME_HEIGHT;
    map2_posY = 0;

    scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    map1_posY += scroll_speed;
    if(map1_posY >= 0)
    {
        map1_posY = -GAME_HEIGHT;
    }
    map2_posY += scroll_speed;
    if(map2_posY >= GAME_HEIGHT)
    {
        map2_posY = 0;
    }




}



































