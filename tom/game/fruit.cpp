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
    int dropRate[8];
    for(i;i<6;i++){
        dropRate[i]=0;
    }
    for(i;i<8;i++){
        dropRate[i]=2;
    }
    dropRate[9] = 1;

    
    this->fruitX = (rand() % SIZE);
    this->fruitY = (rand() % SIZE);
    this->formNb = dropRate[(rand()% 9)];

}
