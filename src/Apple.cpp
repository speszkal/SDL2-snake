#include "dependencies.h"

Apple::Apple(int x, int y, int width, int height, SDL_Renderer *r)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->renderer = r;
}

Apple::~Apple()
{}

void Apple::reset()
{
    x = 16 * random(1, 31);
    y = 16 * random(1, 31);
}

void Apple::update()
{

}

void Apple::render()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}