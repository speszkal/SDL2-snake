#include "dependencies.h"

std::vector<Body*> snake;
Head *head;
Apple *apple;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout<<"SDL could not initialize! SDL_Error: " << SDL_GetError() <<std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(window == NULL)
    {
        std::cout<<"Window could not be created! SDL_Error: " << SDL_GetError() <<std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if(renderer == NULL)
    {
        std::cout<< "Renderer could not be created! SDL Error: " << SDL_GetError() <<std::endl;
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    head = new Head(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 16, 16, renderer);
    snake.push_back( new Body(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 16, 16, renderer) );
    snake.push_back( new Body(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 16, 16, renderer) );
    
    head->dx = -1;
    snake[0]->dx = -1;
    snake[1]->dx = -1;

    apple = new Apple( 16 * random(1, 31), 16 * random(1, 31), 16, 16, renderer );

    score = 0;
    
    running = true;
    
    return true;
}

bool Game::loadMedia()
{
    return true;
}

void Game::handleEvents()
{
    while(SDL_PollEvent(&e) != 0)
    {
        if(e.type == SDL_QUIT)
        {
            running = false;
        }
        else if(e.type == SDL_KEYDOWN)
        {
            if(e.key.keysym.sym == SDLK_ESCAPE) running = false;
            keyPressed[e.key.keysym.sym] = true;
        }
    }
}

void Game::update()
{ 
    if( head->collides(apple->x, apple->y, apple->width, apple->height) )
    {
        score++;

        std::pair<int, int> pos = snake[snake.size()-1]->prevPos();
        snake.push_back( new Body(pos.f, pos.s, 16, 16, renderer) );

        apple->reset();
    }
    
    for(int i=2; i<snake.size()-1; i++)
    {
        Body *obj = snake[i];
        
        if( head->collides(obj->x, obj->y, obj->width, obj->height) )
        {
            std::cout<<"Score: "<<score<<std::endl;
            running = false;
        }
    }
    

    std::pair<int, int> currentMove = head->lastMove;
    head->update();

    for(auto obj : snake)
    {
        obj->dx = currentMove.f;
        obj->dy = currentMove.s;
        currentMove = obj->lastMove;
        
        obj->update();
    }

    //for(auto key : keyPressed) key.s = false;
    keyPressed[SDLK_UP] = false;
    keyPressed[SDLK_DOWN] = false;
    keyPressed[SDLK_LEFT] = false;
    keyPressed[SDLK_RIGHT] = false;
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    
    apple->render();
    for(auto obj : snake)
    {
        obj->render();
    }
    head->render();
    
    SDL_RenderPresent(renderer);
}

void Game::close()
{   
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    delete head;
    for(auto obj : snake) { delete obj; }
    
    SDL_Quit();
}