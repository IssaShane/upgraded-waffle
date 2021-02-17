#include "ItemManager.h"
#include "State.h"

ItemManager::ItemManager()
{
    Item1 = new Item{"data/MulticolorGems_Moosader.png",SDL_Rect{400,0,32,32},SDL_Rect{0,0,32,32}};
    Item1->initType(1);
}

ItemManager::~ItemManager() {
    delete Item1;
}

void ItemManager::draw( SDL_Surface *Screen, bool IsInMenu )
{
    Item1->draw(Screen,IsInMenu);
}

void ItemManager::notify(State &st) {
    if (st.type == StateType::draw) this->draw(st.Screen, false);
}

void ItemManager::Update( SDL_Rect PlayerPos, SDL_Rect EnemyPos, int CollY, int currentLevel )
{
    //If collided with player
    if ( Item1->getPos().x < PlayerPos.x + PlayerPos.w &&
         Item1->getPos().x + Item1->getPos().w > PlayerPos.x &&
         Item1->getPos().y < PlayerPos.y + PlayerPos.h &&
         Item1->getPos().y + Item1->getPos().h > PlayerPos.y )
         {
             Item1->Activate( 1 );
             currentItem = 0;
             Item1->Collect();
         }
         else
         {
             Item1->deActivate();
         }
         Item1->Update( CollY, currentLevel );
    if ( Item1->getPos().x < EnemyPos.x + EnemyPos.w &&
         Item1->getPos().x + Item1->getPos().w > EnemyPos.x &&
         Item1->getPos().y < EnemyPos.y + EnemyPos.h &&
         Item1->getPos().y + Item1->getPos().h > EnemyPos.y )
         {
            Item1->Activate( 1 );
            currentItem = 0;
            Item1->Collect();
         }
}

void ItemManager::UpdateAlt( int AltStartChange, int AltEndChange, int AltChange )
{
    if ( currentItem == 0 )
    {
        Item1->UpdateAlt( AltStartChange, AltEndChange, AltChange );
    }
}

int ItemManager::returnAffectedObj()
{
    if ( currentItem == 0 )
        return Item1->getAffectedObj();
    else return -1;
}

int ItemManager::returnType()
{
    if ( currentItem == 0 )
        return Item1->getType();
    else return -1;
}

int ItemManager::returnTimesCollected()
{
    if ( currentItem == 0 )
        return Item1->getTimesCollected();
    else return -1;
}
