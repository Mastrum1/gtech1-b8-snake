#include "fruit.hpp"
#include "snake.hpp"

Fruit::Fruit(int fruitX,int fruitY,int formNb, Snake* snake)
{
    srand(time(NULL));
    
    this->fruitX = (rand() % SIZE);
    this->fruitY = (rand() % SIZE);
    this->formNb = 0;
    std::cout << this->fruitX << std::endl;
}

Fruit::~Fruit(){}

int Fruit::getX()
{return fruitX;}

int Fruit::getY()
{return fruitY;}

int Fruit::getForm()
{return formNb;}

void Fruit::eaten(Snake * snake)
{  
    int i = 0;
    int dropRate[10] = {0,0,0,0,0,2,2,2,2,1};

    this->fruitX = (rand() % SIZE);
    this->fruitY = (rand() % SIZE);
    this->formNb = dropRate[(rand()% 9)];

}
