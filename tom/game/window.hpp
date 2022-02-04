

#pragma once

#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"







class Game{
    public:
        Game();
        ~Game();
        int init(const char* title, int xpos, int ypos, int width, int height, bool a);
        void render();
        void update();
        void clean();
        SDL_Renderer* getRenderer() {return renderer;}

        bool running() {return isRunning;}
    private:
        bool isRunning = true;
        SDL_Renderer* renderer;
        SDL_Window* window;  //Déclaration de la fenêtre
        

};

