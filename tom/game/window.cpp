#include <iostream>
#include "window.hpp"


Game::Game()
{}

Game::~Game()
{}

int Game::init(const char* title, int xpos, int ypos, int width, int height, bool a)
{       
        int SDL_Init(SDL_INIT_EVERYTHING);
        
        window = SDL_CreateWindow(title, xpos, ypos, width , height , a);  
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
       
        if(window == NULL)//error ?
            {
                std::cout << "Erreur" << std::endl;
                return EXIT_FAILURE;
            }
        if(renderer == NULL)//error ?
            {
                std::cout << "Erreur" << std::endl;
                return EXIT_FAILURE;
            }
       return isRunning = true;
}

void Game::update()
{
        SDL_RenderPresent(renderer);
}


void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    std::cout << "End" << std::endl;
    SDL_Quit();
}