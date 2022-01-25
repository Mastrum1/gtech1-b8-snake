#include <iostream>
#include "window.hpp"


Game::Game()
{}

Game::~Game()
{}

int Game::init(const char* title, int xpos, int ypos, int width, int height)
{       
       
        window = SDL_CreateWindow(title, xpos, ypos, width , height , SDL_WINDOW_RESIZABLE);  
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(window == NULL)//gestion des erreurs
            {
                std::cout << "Erreur" << std::endl;
                return EXIT_FAILURE;
            }
        if(renderer == NULL)//gestion des erreurs
            {
                std::cout << "Erreur" << std::endl;
                return EXIT_FAILURE;
            }
       return isRunning = true;
       
}

void Game::update()
{

}


void Game::clean()
{
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    std::cout << "End" << std::endl;
    SDL_Quit();
}