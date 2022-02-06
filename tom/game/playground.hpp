#pragma once
#include "fruit.hpp"
#include "snake.hpp"


class Playground {
    public:
    Playground();
    ~Playground();
    void create(SDL_Renderer* renderer);
    void displayFruit(SDL_Renderer* renderer, int x, int y, int form);
    void setDisplayState(bool state);
    void collisionFruit(Fruit* fruit,Snake* snake);
    bool getFruitDisplayState(); //function that'll return if a fruit is on the map or not+
    private:
    bool fruitOnDisplay = false;
};