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

