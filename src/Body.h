#ifndef Body_h
#define Body_h

class Body
{
    public:
        int x, y, width, height;
        int dx, dy;
        float xpix, ypix;
        std::pair<int, int> lastMove;

        SDL_Renderer *renderer;

        Body(int x, int y, int width, int height, SDL_Renderer *r);
        ~Body();

        std::pair<int, int> prevPos();

        virtual void update();
        virtual void render();
};

#endif // Body_h