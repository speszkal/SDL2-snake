#ifndef Apple_h
#define Apple_h

class Apple
{
    public:
        int x, y, width, height;

        SDL_Renderer *renderer;

        Apple(int x, int y, int width, int height, SDL_Renderer *r);
        ~Apple();

        void reset();

        virtual void update();
        virtual void render();
};

#endif // Apple_h