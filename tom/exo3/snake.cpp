#include "window.hpp"
#include "window.cpp"
#include "rect.cpp"
#include "rect.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



Game window;

int main(void){
    
    window.init("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,500);

    
    Rect rectangle;
    SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
    rectangle.createRect(window.getRenderer(),50,50);


    while (window.running() == true)
    {
        
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_W]) 
            {
                SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
                SDL_RenderClear(window.getRenderer());
                SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
                rectangle.move(0,-1);
                rectangle.createRect(window.getRenderer(),50,50);
                printf("Key pressed\n");
            }
        if (state[SDL_SCANCODE_S]) 
            {
                SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
                SDL_RenderClear(window.getRenderer());
                SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
                rectangle.move(0,1);
                rectangle.createRect(window.getRenderer(),50,50);
                printf("Key pressed\n");
            }            
        if (state[SDL_SCANCODE_D]) 
            {
                SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
                SDL_RenderClear(window.getRenderer());
                SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
                rectangle.move(1,0);
                rectangle.createRect(window.getRenderer(),50,50);
                printf("Key pressed\n");
            } 
            if (state[SDL_SCANCODE_A]) 
            {
                SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
                SDL_RenderClear(window.getRenderer());
                SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
                rectangle.move(-1,0);
                rectangle.createRect(window.getRenderer(),50,50);
                printf("Key pressed\n");
            } 
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