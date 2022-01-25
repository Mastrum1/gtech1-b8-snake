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

void Rect::move(int x, int y)
{
    xpos += x;
    std::cout << ypos << std::endl;
    ypos += y;
}


