#include "craft.h"

Craft::Craft()
{
    J20_skin.load(CRAFT);
    x = (GAME_WIDTH - J20_skin.width()) * 0.5;
    y = GAME_HEIGHT - J20_skin.height();
    rect.setWidth(J20_skin.width());
    rect.setHeight(J20_skin.height());
    rect.moveTo(x,y);
}

void Craft::shoot()
{
    this->record ++;
    if(this->record <= BULLET_INTERVAL )
    {
        return;
    }
    this->record = 0;
    for(int i = 0; i < BULLET_NUM; ++ i)
    {
        if(this->dots[i].Free == true)
        {
            this->dots[i].Free = false;
            this->dots[i].X = this->x;
            this->dots[i].Y = this->y;
            break;
        }
    }
    for(int j = 0; j < BULLET_NUM; ++ j)
    {
        if(this->dots2[j].Free == true)
        {
            this->dots2[j].Free = false;
            this->dots2[j].X = this->x + J20_skin.width() - 20;
            this->dots2[j].Y = this->y;
            break;
        }
    }


}

void Craft::move(int x, int y)
{
    this->x = x;
    this->y = y;
    rect.moveTo(this->x,this->y);
}
