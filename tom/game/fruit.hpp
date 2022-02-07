#pragma once
#include "snake.hpp"

class Fruit {
    public:
        Fruit(int fruitX, int fruitY, int form, Snake* snake);
        ~Fruit();
        

        int getX();
        int getY();
        int getForm(); 

        void eaten(Snake * snake); //function that'll reattribute x,y and form when eaten
   

    private:
        int fruitX;
        int fruitY;
        int formNb;

};