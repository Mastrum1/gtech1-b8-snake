#include "fruit.hpp"

Fruit::Fruit(int fruitX,int fruitY,int formNb)
{
    srand(time(NULL));
    this->fruitX = (rand() % SIZE) * PAS;
    this->fruitY = (rand() % SIZE) * PAS;
    this->formNb = 1;
    std::cout << this->fruitX << std::endl;
}

Fruit::~Fruit(){}

int Fruit::getX()
{return fruitX;}

int Fruit::getY()
{return fruitY;}

int Fruit::getForm()
{return formNb;}


void Fruit::eaten()
{
    this->fruitX = (rand() % SIZE) * PAS;
    this->fruitY = (rand() % SIZE) * PAS;
    this->formNb = 1;
}



