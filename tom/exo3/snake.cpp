#include "window.hpp"
#include "window.cpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



Game window;

int main(void){
    window.init("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,500);
    
    while (window.running() == true)
    {

    window.update();
    // Get the next event
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
        window.clean();
        break;
        }
    }
    }  
    
    return 0;
}