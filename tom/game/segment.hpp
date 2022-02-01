#pragma once



     
class Segment {
public:
  Segment* next;
  Segment(int x, int y, int dir);
  ~Segment();
   int getX();
   int getY();
   int getDir();
   void setX(int x);
   void setY(int y);
   void setDir(int direction);

private:
  int x;
  int y;
  int dir;
  
};