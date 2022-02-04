#define SIZE 30
#define PAS 35 //sizeof my snake and also the constant that i'll use to draw my board and define the size of my window
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3


#include "window.hpp"
#include "snake.hpp"
#include "segment.hpp"
#include "window.cpp"
#include "snake.cpp"
#include "segment.cpp"
#include "playground.cpp"
#include "playground.hpp"



#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



Game window;
int game = true;
<<<<<<< HEAD

=======
>>>>>>> cb9e7371eea0d4b91ed16f135fa459117563865d

void collision(int xpos)
{
    if (xpos == 750){game = false;}
}

<<<<<<< HEAD
int direction(int direction){
    return 0;
}

=======
>>>>>>> cb9e7371eea0d4b91ed16f135fa459117563865d
int main(){
    
    int direction = 0;

    int frame_rate_ms = 60;
    int snake_speed_fpc = 7;

    int frame_delay,snake_status;
    Uint32 frame_start;

<<<<<<< HEAD
    int frame_rate_ms = 60;

    int frame_delay,snake_status;
    Uint32 frame_start;

    Uint32 iter;

    window.init("Snake",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,PAS*SIZE,PAS*SIZE,false);
=======
    Uint32 iter;

    window.init("Snake",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,500,false);
>>>>>>> cb9e7371eea0d4b91ed16f135fa459117563865d
    SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
    Snake *snake = new Snake(3,RIGHT);
    Playground *playground = new Playground();
    //std::cout << "Bein" << std::endl;

    do{
        frame_start = SDL_GetTicks();

        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
            window.clean();
            break;
            }
        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_W]) 
        {
<<<<<<< HEAD
            snake->turnSnake(UP);
        }
        if (state[SDL_SCANCODE_S]) 
        {
            snake->turnSnake(DOWN);
        }
        if (state[SDL_SCANCODE_D]) 
        {
            snake->turnSnake(RIGHT);
        }
        if (state[SDL_SCANCODE_A]) 
        {
            snake->turnSnake(LEFT);
        }
        if (state[SDL_SCANCODE_C]) 
        {
            snake->growBack();
        }    
        SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(window.getRenderer());
        SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
        playground->create(window.getRenderer());
        snake->print(window.getRenderer(),false);
        window.update();;
=======
            snake->turnSnake(0);
        }
        if (state[SDL_SCANCODE_S]) 
        {
            snake->turnSnake(1);
        }
        if (state[SDL_SCANCODE_D]) 
        {
            snake->turnSnake(2);
        }
        if (state[SDL_SCANCODE_A]) 
        {
            snake->turnSnake(3);
        }
            
        SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(window.getRenderer());
        SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
        snake->print(window.getRenderer());
        window.update();
>>>>>>> cb9e7371eea0d4b91ed16f135fa459117563865d
            

        frame_delay = frame_rate_ms - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0)
            SDL_Delay(frame_delay);
            snake->move();
        if (frame_delay > frame_rate_ms)
            printf("WARNING: frame rate drop: %d ms\n", frame_delay - frame_rate_ms);


        // Get the next event

        iter++;
<<<<<<< HEAD
    }while (snake->collisionMur() == false && snake->collisionSnake() == false);
    
    return 0;
}
=======
    }while (game == true);
    
    return 0;
}

>>>>>>> cb9e7371eea0d4b91ed16f135fa459117563865d
