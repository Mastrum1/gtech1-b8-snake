#pragma once

#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"

class Fruit {
    public:
        Fruit(int fruitX, int fruitY, char form);
        ~Fruit();
        void print(SDL_Renderer* renderer,bool rgb);
        int getX();
        int getY();
        char getForm();
        void setX(int x);
        void setY(int y);
        void setForm(char form);

    private:
        int fruitX;
        int fruitY;
        int formNb;
        char form;
};