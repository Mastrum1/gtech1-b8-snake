#pragma once
#include <SDL2/SDL.h>

class MainSDLWindow {
    public:
        MainSDLWindow();
        ~MainSDLWindow();
        SDL_Renderer* GetRenderer(void);
        int Init(const char* nom,int hauteur,int largeur);
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
