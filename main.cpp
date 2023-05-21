#include "src/dependencies.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    
    Game game;
    
    if(!game.init("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, false))
    {
        std::cout<<"ERROR: Game could not be initialized."<<std::endl;
        game.close();
        return 0;
    }

    if(!game.loadMedia())
    {
        std::cout<<"ERROR: Failed to load media."<<std::endl;
        game.close();
        return 0;
    }

    Uint32 frameStart = SDL_GetTicks();
    int frameTime;
    
    game.render();
    while(game.isRunning())
    {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
    }
    game.close();

    return 0;
}