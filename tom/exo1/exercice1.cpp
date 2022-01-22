#include "exercice1.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


class MainSDLWindow{
    public:
        MainSDLWindow(void){
            this->window = NULL;
            this->renderer = NULL;

        }
        int init(const char* name,int l,int h){
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
        ~MainSDLWindow(void){
            SDL_Delay(3000);  //pause de 3 secondes

            SDL_DestroyRenderer(renderer); 
            SDL_DestroyWindow(window);
            SDL_Quit(); // On quitte la SDL
        }
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;   
}; 

int main(void) {
    
    MainSDLWindow window;
    window.init("mafenetre",500,500);
    
   
    return 0;
}