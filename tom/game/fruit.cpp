#include "fruit.hpp"
#include "snake.hpp"

Fruit::Fruit(int fruitX,int fruitY,int formNb, Snake* snake)
{
    srand(time(NULL));
    
    this->fruitX = (rand() % SIZE) * PAS;
    this->fruitY = (rand() % SIZE) * PAS;
    this->formNb = 1;
    while(fruitX == snake->getHead().getX() && fruitY == snake->getHead().getY())
    {
        this->fruitX = (rand() % SIZE) * PAS;
        this->fruitY = (rand() % SIZE) * PAS; 
    }
    std::cout << this->fruitX << std::endl;
}

Fruit::~Fruit(){}

int Fruit::getX()
{return fruitX;}

int Fruit::getY()
{return fruitY;}

int Fruit::getForm()
{return formNb;}


void Fruit::eaten(Snake* snake)
{

    this->fruitX = (rand() % SIZE) * PAS;
    this->fruitY = (rand() % SIZE) * PAS;
    this->formNb = (rand() % FRUIT_NUMBER);
    while(fruitX == snake->getHead().getX() && fruitY == snake->getHead().getY())
    {
        this->fruitX = (rand() % SIZE) * PAS;
        this->fruitY = (rand() % SIZE) * PAS; 
    }
}



