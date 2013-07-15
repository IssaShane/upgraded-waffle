#include "System.h"

System::System()
{
    quit = false;
    SDL_Init( SDL_INIT_EVERYTHING );
    frameRate = 1000 / 60;
}

void System::Run()
{
    while ( quit == false )
    {
        frameStart = SDL_GetTicks();
        while ( SDL_PollEvent( &event ) )
        {
            if ( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        Sprite.draw();
        frameDuration = SDL_GetTicks() - frameStart;
        if( frameDuration < frameRate )
            SDL_Delay(frameRate - frameDuration);
    }
}

System::~System()
{
    SDL_Quit();
}
