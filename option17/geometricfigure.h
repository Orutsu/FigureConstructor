#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H
#include "windows.h"

enum{Square, Rectangle, Circle, Triangle, Elipse};


class geometricFigure
{
protected:
    int x;
    int y;
public:
    geometricFigure(){

    }
    geometricFigure(int newX, int newY){
        x = newX;
        y = newY;
    }
    int type;
    virtual void findArea();
    int getY() const{
        return y;
    }

    void setY(int value)
    {
        y = value;
    }

    int getX() const
    {
        return x;
    }

    void setX(int value)
    {
        x = value;
    }

    int getyourAss()
    {
        return 90;
    }
};

#include<geometricfigure.cpp>

#endif // GEOMETRICFIGURE_H
