#include <iostream>
#include "rect.hpp"


Rect::Rect()
{}

Rect::~Rect()
{}

void Rect::createRect(SDL_Renderer* renderer,int width,int height)
{
    rectangle = {xpos,ypos,width,height};

    SDL_RenderDrawRect(renderer, &rectangle);
}

void Rect::move(int dir)
{

    switch (dir){
        case 0 :
            ypos -= pas;
            break;
        case 1 :
            ypos += pas;
            break;
        case 2 :
            xpos += pas;
            break;
        case 3 :
            xpos -= pas;
            break;
        default:
            break;
    }

}


