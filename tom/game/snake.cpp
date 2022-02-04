#include <iostream>
#include "snake.hpp"


Snake::Snake(int length, int startDirection)
{   
    std::cout << "construction" << std::endl;
    int x = PAS*(SIZE/2);
    int y = PAS*(SIZE/2);
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
    case UP:
        if (head->getDir() != DOWN)
            head->setDir(dir);
        break;
    case DOWN:
        if (head->getDir() != UP)
            head->setDir(dir);
        break;
    case RIGHT:
        if (head->getDir() != LEFT)
            head->setDir(dir);
        break;
    case LEFT:
        if (head->getDir() != RIGHT)
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
    case UP:
        yPos -= PAS;
        break;
    case DOWN:
        yPos += PAS;
        break;
    case RIGHT:
        xPos += PAS;
        break;
    case LEFT:
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
    case UP:
        yPos += PAS;
        break;
    case DOWN:
        yPos -= PAS;
        break;
    case RIGHT:
        xPos -= PAS;
        break;
    case LEFT:
        xPos += PAS;
        break;
    default:
        break;
    }

    Segment *newSegment  = new Segment(xPos, yPos, loop->getDir());
    newSegment->setY(yPos);
    newSegment->setDir(head->getDir());
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

int R = 255;
int G = 0;
int B = 0;

void Snake::print(SDL_Renderer* renderer,bool rgb)
{
    Segment *loop = head;
    if (head == NULL)
    return;

    std::cout << head->getDir() << std::endl;
    std::cout << head->getX() << std::endl;
    std::cout << head->getY() << std::endl;

    while (loop != NULL)
    {   
        if (rgb == true){
            if (R == 255 && G < 255){
                G+=3;
            }
            else if (R > 0 && G == 255){
                R-=3;
            }
            else if (G == 255 && B < 255){
                B+=3;
            }
            //RGB Mode
            else if (G > 0 && B == 255){
                G-=3;
            }
            else if (B == 255 && R < 255){
                R+=3;
            }
            else if (R == 255 && B > 0){
                R+=3;
            }
        }

        SDL_SetRenderDrawColor(renderer,R,G,B,SDL_ALPHA_OPAQUE);
        SDL_Rect rectangle;
        rectangle = {loop->getX(),loop->getY(),PAS,PAS};
        SDL_RenderFillRect(renderer, &rectangle);
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

bool Snake::collisionSnake()
{
    bool hit = false;
    Segment* loop = head->next;

    while (loop != NULL)
    {

        if (head->getX() == loop->getX() && head->getY() == loop->getY())
        {
            hit = true;
            break;

        }
        loop = loop->next;
    }
    return hit;
}


