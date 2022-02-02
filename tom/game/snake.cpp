#include <iostream>
#include "snake.hpp"



Snake::Snake(int length, int startDirection)
{   
    std::cout << "construction" << std::endl;
    int x = PAS*10;
    int y = PAS*10;
    for(int i=0; i < length; i++)
    {
        std::cout << "aller" << std::endl;
        switch (startDirection)
        {
        case 0:
        case 1:
            y += PAS;
            break;
        case 2:
        case 3:
            x += PAS;
            break;
        default:
            break;
        }
        grow(x,y,startDirection);
    }

    std::cout << "mon snake est créé" << std::endl;
    this->dir = startDirection;
    std::cout << startDirection << std::endl;
}

Segment Snake::getHead()
{return *head;}

void Snake::move()
{
    delBack();
    growAtHead();
}

void Snake::turnSnake(int dir)
{

    switch (dir)
    {
    case 0:
        if (head->getDir() != 1)
            head->setDir(dir);
        break;
    case 1:
        if (head->getDir() != 0)
            head->setDir(dir);
        break;
    case 2:
        if (head->getDir() != 3)
            head->setDir(dir);
        break;
    case 3:
        if (head->getDir() != 2)
            head->setDir(dir);
        break;
    default:
        break;
    }
}
void Snake::grow(int x, int y, int dir)
{

    std::cout << "Initialisation de mon snake" << std::endl;
    Segment *newSegment = new Segment(x, y, 2);
    int xPos = x;
    std::cout << xPos<< std::endl;
    int yPos = y;

    if (head == NULL)
    {
        std::cout << "voici ma tête" << std::endl;
        head = newSegment;
        
        return;
    }
 

    newSegment->setX(xPos);
    newSegment->setY(yPos);
    newSegment->setDir(dir);
    newSegment->next = head;
    head = newSegment;

}

void Snake::growAtHead()
{
    
    int xPos = head->getX();
    int yPos = head->getY();

    if (head == NULL)
    {
 
        return;
    }

    switch (head->getDir())
    {
    case 0:
        yPos -= PAS;
        break;
    case 1:
        yPos += PAS;
        break;
    case 2:
        xPos += PAS;
        break;
    case 3:
        xPos -= PAS;
        break;
    default:
        break;
    }


    Segment *newSegment = new Segment(xPos, yPos, dir);
    newSegment->setX(xPos);
    newSegment->setY(yPos);
    newSegment->setDir(head->getDir());
    newSegment->next = head;
    head = newSegment; 
}

void Snake::growBack()
{
    Segment *loop = head;

    while (loop->next != NULL)
    {
        loop = loop->next;
    }

    int xPos = loop->getX();
    int yPos = loop->getY();

    switch (loop->getDir())
    {
    case 0:
        yPos += PAS;
        break;
    case 1:
        yPos -= PAS;
        break;
    case 2:
        xPos -= PAS;
        break;
    case 3:
        xPos += PAS;
        break;
    default:
        break;
    }

    Segment *newSegment  = new Segment(xPos, yPos, loop->getDir());
    newSegment->setY(yPos);
    newSegment->setDir(head->getDir());
    newSegment->next = head;
    loop->next = newSegment;



}


void Snake::delBack()
{
    Segment *loop = head;
    Segment *last = NULL;
    if(head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while(loop->next->next != NULL)
        {
            loop = loop->next;
        }
        last = loop->next;
        loop->next = NULL;
        delete last;
    }


}



void Snake::print(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer,23,73,194,SDL_ALPHA_OPAQUE);
    Segment *loop = head;
    if (head == NULL)
    return;
    std::cout << head->getDir() << std::endl;
    std::cout << head->getX() << std::endl;
    std::cout << head->getY() << std::endl;

    while (loop != NULL)
    {
        
        SDL_Rect rectangle;
        rectangle = {loop->getX(),loop->getY(),PAS,PAS};
        SDL_RenderFillRect(renderer,&rectangle);
        SDL_RenderDrawRect(renderer, &rectangle);
        loop = loop->next;  
        
    }
    
}

bool Snake::collisionMur()
{
    if (head->getX() > (SIZE-1)*PAS || head->getX() < 0 || head->getY() > (SIZE-1)*PAS || head->getY() < 0)
    {
        return true;
    }
    else{
        return false;
    }
}


