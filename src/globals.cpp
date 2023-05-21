#include "dependencies.h"

std::map<SDL_Keycode, bool> keyPressed;

int random(int a, int b)
{
    return a + rand() % (b-a+1);
}