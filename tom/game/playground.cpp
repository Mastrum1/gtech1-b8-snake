#include "playground.hpp"


Playground::Playground()
{
}

Playground::~Playground()
{}

void Playground::create(SDL_Renderer* renderer)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int l = 0; l < SIZE; l++)
        {
            SDL_Rect square;
            square = {PAS*l,PAS*i,PAS,PAS};
            switch(i%2)
            {
                case 0:
                    if (l%2 == 0)
                    {
                        SDL_SetRenderDrawColor(renderer,0,200,3,SDL_ALPHA_OPAQUE);
                    }
                    else
                    {
                        SDL_SetRenderDrawColor(renderer,28,168,28,SDL_ALPHA_OPAQUE);
                    }
                    break;
                case 1:
                    if (l%2 == 0)
                    {
                        SDL_SetRenderDrawColor(renderer,28,168,28,SDL_ALPHA_OPAQUE);
                    }
                    else
                    {
                        SDL_SetRenderDrawColor(renderer,0,200,3,SDL_ALPHA_OPAQUE);
                    }
                    break;
                default:
                    break;

            }
            SDL_RenderFillRect(renderer,&square);
            SDL_RenderDrawRect(renderer, &square);
        }
    }
}


void Playground::setDisplayState(bool state)
{
    this->fruitOnDisplay = state;
}
void Playground::displayFruit(SDL_Renderer* renderer,int x, int y, int form)
{
    SDL_SetRenderDrawColor(renderer,129,23,23,SDL_ALPHA_OPAQUE);
    SDL_Rect apple;
    apple = {x,y ,PAS,PAS};
    SDL_RenderFillRect(renderer, &apple);
    SDL_RenderDrawRect(renderer, &apple);
}

bool Playground::getFruitDisplayState()
{
    return fruitOnDisplay;
}

void Playground::collisionFruit(Fruit* fruit, Snake* snake)

{
    if (fruit->getX() == snake->getHead().getX() && fruit->getY() == snake->getHead().getY())
    {
        snake->growBack();
        setDisplayState(false);
        fruit->eaten();   
    }
}