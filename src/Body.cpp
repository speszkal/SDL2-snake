#include "dependencies.h"

Body::Body(int x, int y, int width, int height, SDL_Renderer *r)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->renderer = r;

    lastMove = {0, 0};
    dx = 0;
    dy = 0;
    xpix = 0;
    ypix = 0;
}

Body::~Body()
{}

std::pair<int, int> Body::prevPos()
{
    return {x - 16*lastMove.f, y - 16*lastMove.s};
}

void Body::update()
{
    /*xpix += (float)dx/10;
    ypix += (float)dy/10;

    if(xpix < -1 || xpix > 1)
    {
        xpix = 0;
        x += 16*dx;
    }

    if(ypix < -1 || ypix > 1)
    {
        ypix = 0;
        y += 16*dy;
    }*/

    x += 16*dx;
    y += 16*dy;

    lastMove = { dx, dy };
}

void Body::render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}