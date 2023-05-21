#include "dependencies.h"

Head::Head(int x, int y, int width, int height, SDL_Renderer *r) : Body(x, y, width, height, r)
{}

bool Head::collides(int obj_x, int obj_y, int obj_width, int obj_height)
{
    if(x+1 > obj_x + obj_width || obj_x > x + width-1) return false;

    if(y+1 > obj_y + obj_height || obj_y > y + height-1) return false;

    return true;
}

void Head::update()
{
    if(keyPressed[SDLK_UP] && dy == 0)
    {
        dx = 0;
        dy = -1;

        xpix = 0;
    }
    else if(keyPressed[SDLK_DOWN] && dy == 0)
    {
        dx = 0;
        dy = 1;

        xpix = 0;
    }
    else if(keyPressed[SDLK_LEFT] && dx == 0)
    {
        dx = -1;
        dy = 0;

        ypix = 0;
    }
    else if(keyPressed[SDLK_RIGHT] && dx == 0)
    {
        dx = 1;
        dy = 0;

        ypix = 0;
    }

    Body::update();
}

void Head::render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0xAA, 0x00, 0xFF);
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}