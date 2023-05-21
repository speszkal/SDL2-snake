#ifndef Game_h
#define Game_h

class Game
{   
    public:
        bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        bool loadMedia();

        void handleEvents();
        void update();
        void render();

        bool isRunning() { return running; };

        void close();

    private:
        bool running = false;

        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;

        SDL_Event e;

        int score;
};

#endif // Game_h