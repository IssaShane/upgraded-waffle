#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Item.h"
#include <iostream>
#include "Observer.h"

class ItemManager : public Observer
{
    public:
        ItemManager();
        ~ItemManager();
        void draw( SDL_Surface *Screen, bool IsInMenu );
        virtual void notify(State&) override;
        void Update( SDL_Rect PlayerPos, SDL_Rect EnemyPos, int CollY, int currentLevel );
        void UpdateAlt( int AltChangeStart, int AltChangeEnd, int AltChange );
        int returnAffectedObj();
        int returnType();
        int returnTimesCollected();

    private:
        Item *Item1;
        int currentItem;
};

#endif
