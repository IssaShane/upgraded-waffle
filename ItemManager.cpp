#include "ItemManager.h"

ItemManager::ItemManager()
{
    Item1.init("data/MulticolorGems_Moosader.png", 400, 0, 0, 0, 32, 32 );
    Item1.initType(1);
}

void ItemManager::draw( SDL_Surface *Screen, bool IsInMenu )
{
    if ( IsInMenu == false )
        Item1.draw( Screen );
}

void ItemManager::Update( SDL_Rect PlayerPos, int CollY )
{
    //If collided with player
    if ( Item1.returnPos().x < PlayerPos.x + PlayerPos.w &&
         Item1.returnPos().x + Item1.returnPos().w > PlayerPos.x &&
         Item1.returnPos().y < PlayerPos.y + PlayerPos.h &&
         Item1.returnPos().y + Item1.returnPos().h > PlayerPos.y )
         {
             Item1.Activate( 1 );
             currentItem = 0;
             Item1.Collect();
         }
         else
         {
             Item1.deActivate();
         }
         Item1.Update( CollY );
}

int ItemManager::returnAffectedObj()
{
    if ( currentItem == 0 )
        return Item1.returnAffectedObj();
}

int ItemManager::returnType()
{
    if ( currentItem == 0 )
        return Item1.returnType();
}

int ItemManager::returnTimesCollected()
{
    if ( currentItem == 0 )
        return Item1.returnTimesCollected();
}
