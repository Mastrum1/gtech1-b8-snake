#pragma once
#include "segment.hpp"

class Snake {
public:
  Snake(int length, int startDirection);
  ~Snake();
  Segment getHead(); // return the head of the snake
  void move(); //function that'll delete the tail and grow a new head on the head
  void turnSnake(int dir); // function that'll change turn the snake and avoid going north when facing south
  void growAtHead(); //function that'll grow on the head
  void delBack(); // function that'll delete the last cube
  void grow(int x, int y, int dir); // function that'll take pos and dir for the init of the snake
  void growBack();  //function that'll grow at the tail
  void print(SDL_Renderer* renderer,bool rgb); //function that'll print the whole snake
  
  bool collisionMur(); //function that'll check if i hit a wall or no ?
  bool collisionSnake(); //function that'll check if I hit my body or no ?

private:
  int dir; 
  Segment* head = NULL;
};
