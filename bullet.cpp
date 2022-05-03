#include "bullet.h"
#include "config.h"
Bullet::Bullet()
{
    Bullet_skin.load(BULLET);
    this->X = GAME_WIDTH * 0.5 - Bullet_skin.width() * 0.5;
    this->Y = GAME_HEIGHT;
    this->Free = true;
    this->Speed = BULLET_SPEED;
    this->Rect.setWidth(Bullet_skin.width());
    this->Rect.setHeight(Bullet_skin.height());
    this->Rect.moveTo(this->X, this->Y);

}

void Bullet::updateBulletPos()
{
    if(this->Free == true)
    {
        return;
    }
    this->Y -= this->Speed;
    this->Rect.moveTo(this->X, this->Y);

    if(this->Y <= - Bullet_skin.height())
    {
        this->Free = true;
    }


}























