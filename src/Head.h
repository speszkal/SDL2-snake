#ifndef Head_h
#define Head_h

class Head: public Body
{
    public:
        Head(int x, int y, int width, int height, SDL_Renderer *r);
        
        bool collides(int obj_x, int obj_y, int obj_width, int obj_height);
        
        void update() override;
        void render() override;
};

#endif // Head_h