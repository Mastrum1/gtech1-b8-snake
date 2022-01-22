#include "exercice2.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>




    int init(const char* name,int l,int h)
    {
        SDL_Renderer* renderer;
        SDL_Window* window;  //Déclaration de la fenêtre
        window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, l , h , SDL_WINDOW_RESIZABLE);  
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
       return EXIT_SUCCESS;
       } 

int main(void){
    SDL_Renderer* renderer;
    SDL_Window* window; 
    init("Rectangle",500,500);
    while (true)
    {
    // Get the next event
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
        // Break out of the loop on quit
        break;
        }
    }
    }  

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}