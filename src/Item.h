#ifndef ITEM_H
#define ITEM_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "GameObject.h"

class Item : public GameObject {
    public:
        Item(const char *, SDL_Rect,SDL_Rect);
        ~Item();
        void initType( int Type );
        void Activate( int ObjName );
        void deActivate();
        void Update( int CollY, int currentLevel );
        void UpdateAlt( int AltChangeStart, int AltChangeEnd, int AltChange );
        void setAffectedObj( int newAffectedObj );
        void Collect();

        // getters
        int getAffectedObj();
        int getType();
        int getTimesCollected();

    private:
        int type;
        int AffectedObj;
        int TimesCollected;
        bool IsAltChange;
};

#endif
