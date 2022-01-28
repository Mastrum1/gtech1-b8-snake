#include "window.hpp"
#include "window.cpp"
#include "rect.cpp"
#include "rect.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



Game window;
int game = true;

void collision(int xpos)
{
    if (xpos == 750){game = false;}
}

int main(void){
    
    int direction = 0;
    window.init("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,500);

    
    Rect rectangle;
    SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
    rectangle.createRect(window.getRenderer(),50,50);


    while (game == true)
    {
        
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_W]) 
        {
            direction = 0;
        }
        if (state[SDL_SCANCODE_S]) 
        {
            direction = 1;
        }
        if (state[SDL_SCANCODE_D]) 
        {
            direction = 2;
        }
        if (state[SDL_SCANCODE_A]) 
        {
            direction = 3;
        }

        SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(window.getRenderer());
        SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
        switch (direction){
            case 0:
                rectangle.move(0,-10);
                break;
            case 1:
                rectangle.move(0,10);
                break;
            case 2:
                rectangle.move(10,0);
                break;
            case 3:
                rectangle.move(-10,0);
                break; 
            default:
                break;           
        }
        SDL_Delay(20);
        rectangle.createRect(window.getRenderer(),50,50);
        collision(rectangle.getX());
                
            
   
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