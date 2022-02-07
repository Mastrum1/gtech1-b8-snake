#pragma once
#include "fruit.hpp"
#include "snake.hpp"


class Playground {
    public:
    Playground();
    ~Playground();
    void create(SDL_Renderer* renderer); // create the playboard
    void displayFruit(SDL_Renderer* renderer, int x, int y, int form); //dislpay the fruit
    void setDisplayState(bool state); //to set if the fruit is on the board or no
    void collisionFruit(Fruit* fruit,Snake* snake); // function that'll do different actions according to the fruit which collided with the snake
    bool getFruitDisplayState(); //function that'll return if a fruit is on the map or not+
    private:
    bool fruitOnDisplay = false;
};