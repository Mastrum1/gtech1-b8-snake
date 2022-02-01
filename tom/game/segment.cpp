#include <iostream>
#include "segment.hpp"

Segment::Segment(int x, int y, int dir)
{
    this->x =x;
    this->y =x;
    this->dir =dir;
    this->next = NULL;

}

Segment::~Segment()
{}

int Segment::getX()
{return x;}

int Segment::getY()
{return y;}

int Segment::getDir()
{return dir;}

void Segment::setX(int x)
{this->x = x;}

void Segment::setY(int y)
{this->y = y;}

void Segment::setDir(int direction)
{this->dir = direction;}