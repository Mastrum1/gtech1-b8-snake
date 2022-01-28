#pragma once


#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"

class Rect{
    public:
        Rect();
        ~Rect();
        void createRect(SDL_Renderer* renderer, int width, int height);

        void move(int dir);
        int getX(){return xpos;};
        int getY(){return ypos;};
 
            

    private:
    int xpos = 400;
    int ypos = 300;
    int pas = 10;
    SDL_Rect rectangle;
    

};

