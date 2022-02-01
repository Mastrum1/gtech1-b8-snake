#include "window.hpp"
#include "snake.hpp"
#include "segment.hpp"
#include "window.cpp"
#include "snake.cpp"
#include "segment.cpp"



#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>




Game window;
int go = true;


int main(void){
    

    window.init("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,500);
    SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
    Snake *snake = new Snake(20,2);
    //std::cout << "Bein" << std::endl;



    while (go == true)
    {   
        
        
        snake->move();

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_W]) 
        {
            snake->turnSnake(0);
            snake->move();
        }
        if (state[SDL_SCANCODE_S]) 
        {
            snake->turnSnake(1);
            snake->move();
        }
        if (state[SDL_SCANCODE_D]) 
        {
            snake->turnSnake(2);
            snake->move();
        }
        if (state[SDL_SCANCODE_A]) 
        {
            snake->turnSnake(3);
            snake->move();
        }


        SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(window.getRenderer());
        SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
        snake->print(window.getRenderer());
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
        SDL_Delay(50);
    }  
    
    return 0;
}