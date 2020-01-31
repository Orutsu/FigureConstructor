#ifndef FIGURE_H
#define FIGURE_H
#include <QMainWindow>
#include <QPair>
#include <QLabel>
#include <math.h>
#include <string>

using namespace std;

enum{Square = 1, Rectangle, Circle, Triangle, Ellipse};

struct Coordinates{
    int x;
    int y;
};

class Figure{
protected:
    Coordinates position;
public:
    Figure();
    Figure(Coordinates cellPosition);
    virtual double findArea(){}
    virtual void findOwnCoord(){}
    virtual double findPerimeter(){}
    virtual double findRadiusOfInCircle(){}
    virtual double findRadiusOfOutCircle(){}
    int getY() const;
    int getX() const;
    virtual ~Figure(){}
};


class FSquare : public Figure{
private:
    int sideSize;
public:
    FSquare();
    void findOwnCoord() override;
    FSquare(Coordinates cellPosition, int side):Figure(cellPosition){
        sideSize = side;
        this->findOwnCoord();
    }
    double findArea() override;
    double findPerimeter() override;
    double findRadiusOfInCircle() override;
    double findRadiusOfOutCircle() override;
    int getSideSize() const;
};

class FRectangle: public Figure{
private:
    int width;
    int height;
public:
    FRectangle();
    void findOwnCoord() override;
    FRectangle(Coordinates cellPosition, int a, int b):Figure(cellPosition){
        width = a;
        height = b;
        this->findOwnCoord();
    }
    double findArea() override;
    double findPerimeter() override;
    double findRadiusOfOutCircle() override;
    int getWidth() const;
    int getHeight() const;
};

class FCircle: public Figure{
private:
    int diameter;
public:
    FCircle();
    void findOwnCoord() override;
    FCircle(Coordinates cellPosition, int r):Figure(cellPosition){
        diameter = r;
        this->findOwnCoord();
    }
    double findArea() override;
    double findPerimeter() override;
    int getDiameter() const;
};

class FTriangle:public Figure{
private:
    Coordinates point1;
    Coordinates point2;
    Coordinates point3;
    double side1;
    double side2;
    double side3;
public:
    FTriangle();
    void findOwnCoord() override;
    FTriangle(Coordinates cellPosition, Coordinates p1, Coordinates p2, Coordinates p3):Figure(cellPosition){
        point1 = p1;
        point2 = p2;
        point3 = p3;
        side1 = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
        side2 = sqrt(pow((point2.x - point3.x), 2) + pow((point2.y - point3.y), 2));
        side3 = sqrt(pow((point1.x - point3.x), 2) + pow((point1.y - point3.y), 2));
        this->findOwnCoord();
    }
    double findArea() override;
    double findPerimeter() override;
    double findRadiusOfInCircle() override;
    double findRadiusOfOutCircle() override;
    double findMiddleLine();
    int getX1() const;
    int getX2() const;
    int getX3() const;
    int getY1() const;
    int getY2() const;
    int getY3() const;
    double findAngle1();
    double findAngle2();
    double findAngle3();
    double getSide1() const;
    double getSide2() const;
    double getSide3() const;
};

class FEllipse:public Figure{
private:
    int width;
    int height;
public:
    FEllipse();
    void findOwnCoord() override;
    FEllipse(Coordinates cellPosition, int a, int b):Figure(cellPosition){
        width = a;
        height = b;
        this->findOwnCoord();
    }
    double findArea() override;
    double findPerimeter() override;
    int getWidth() const;
    int getHeight() const;
};

#endif // FIGURE_H
