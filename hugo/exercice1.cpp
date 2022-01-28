#include <stdio.h>
#include <stdlib.h>
#include "exercice1.hpp"

int main(void){
    MainSDLWindow main_window;
    main_window.Init("Snake", 600, 480);
    SDL_Delay(10000);
    SDL_Quit();//on quitte la SDL
    return 0;
}

//Constructeur
MainSDLWindow::MainSDLWindow(void){
    window = NULL;
    renderer = NULL;
}

//Destructeur
MainSDLWindow::~MainSDLWindow(void){
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window);
    SDL_Quit(); // On quitte la SDL
}

SDL_Renderer* MainSDLWindow::GetRenderer(void){
    return renderer;
}

//Init
int MainSDLWindow::Init(const char* nom,int hauteur,int largeur){
    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création de la fenêtre :
    window = SDL_CreateWindow(nom , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 600 , 600 , SDL_WINDOW_RESIZABLE);
    if(window == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une window : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

    if(renderer == NULL)//gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return EXIT_SUCCESS;
}