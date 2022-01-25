#ifndef rect_hpp
#define rect_hpp


#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"

class Rect{
    public:
        Rect();
        ~Rect();
        void createRect(SDL_Renderer* renderer, int width, int height);

        void move(int x, int y);
 
            

    private:
    int xpos = 400;
    int ypos = 300;
    SDL_Rect rectangle;
    

};


#endif 