#pragma once


class Fruit {
    public:
        Fruit(int fruitX, int fruitY, int form);
        ~Fruit();
        

        int getX();
        int getY();
        int getForm();

        void eaten(); //function that'll reattribute x,y and form when eaten
   

    private:
        int fruitX;
        int fruitY;
        int formNb;

};