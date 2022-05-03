#include "f35.h"

F35::F35()
{
    F35_skin.load(F35_PATH);
    this->F35_X = 1;
    this->F35_Y = 1;

    this->F35_Free = true;

    this->F35_Speed = F35_SPEED;
    this->F35_Rect.setWidth(F35_skin.width());
    this->F35_Rect.setHeight(F35_skin.height());
    this->F35_Rect.moveTo(this->F35_X, this->F35_Y);
}

void F35::updateF35Position()
{
    //空闲未出场 战机， 不计算
    if(this->F35_Free == true)
    {
        return;
    }
    this->F35_Y += this->F35_Speed;
    this->F35_Rect.moveTo(this->F35_X, this->F35_Y);

    if(this->F35_Y > GAME_HEIGHT)
    {
        this->F35_Free = true;

    }

}



























