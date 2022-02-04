#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "fruit.hpp"
#include "main.cpp"

Fruit::Fruit(int fruitX,int fruitY,char form)
{
    srand(time(NULL));
    this->fruitX = (rand()%SIZE)*SIZE;
    this->fruitY = (rand()%SIZE)*SIZE;
    this->formNb = rand()%FRUIT_NUMBER;
}

Fruit::~Fruit(){}

int Fruit::getX()
{return fruitX;}

int Fruit::getY()
{return fruitY;}

char Fruit::getForm()
{return form;}

void Fruit::setX(int x)
{this->fruitX = x*SIZE;}

void Fruit::setY(int y)
{this->fruitY = y*SIZE;}

void Fruit::setForm(char formnb)
{this->formNb = formNb;}

int R = 0;
int G = 0;
int B = 0;

void Fruit::print(SDL_Renderer* renderer,bool rgb)
{
    SDL_SetRenderDrawColor(renderer,R,G,B,SDL_ALPHA_OPAQUE);
    SDL_Rect rectangle;
    rectangle = {this->getX(),this->getY(),PAS,PAS};
    SDL_RenderFillRect(renderer, &rectangle);
    SDL_RenderDrawRect(renderer, &rectangle);
}