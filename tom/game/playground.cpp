#include "playground.hpp"

Playground::Playground()
{}

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

int fruitR = 255;
int fruitG = 0;
int fruitB = 0;

void Playground::displayFruit(SDL_Renderer* renderer,int x, int y, int form)
{   
    switch(form){
        case 0:
            SDL_SetRenderDrawColor(renderer,129,23,23,SDL_ALPHA_OPAQUE);
            break;
        case 1:

            if (fruitR == 255 && fruitG < 255 && fruitB == 0){
                fruitG+=3;
            }
            else if (fruitR > 0 && fruitG == 255){
                fruitR-=3;
            }
            else if (fruitG == 255 && fruitB < 255){
                fruitB+=3;
            }
            //RGB Mode
            else if (fruitG > 0 && fruitB == 255){
                fruitG-=3;
            }
            else if (fruitB == 255 && fruitR < 255){
                fruitR+=3;
            }
            else if (fruitB > 0 && fruitR == 255){
                fruitB-=3;
            }
            SDL_SetRenderDrawColor(renderer,fruitR,fruitG,fruitB,SDL_ALPHA_OPAQUE);

            break;
        case 2:
            SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
            break;
        default:
            break;
    }
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
        switch(fruit->getForm()){
            case 0:
                snake->growBack();
                setDisplayState(false);
                fruit->eaten(snake);  
                break;
            case 1:
                snake->setGamemode(true);
                snake->growBack();
                setDisplayState(false);
                fruit->eaten(snake); 
                break;
            case 2: 
                snake->delBack();
                //rajouter -1 au score
                setDisplayState(false);
                fruit->eaten(snake); 
                break;
        }
    }
}