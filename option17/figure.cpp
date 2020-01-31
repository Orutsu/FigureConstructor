#include "figure.h"

Figure::Figure()
{

}

Figure::Figure(Coordinates cellPosition){
    position = cellPosition;
}

int Figure::getX() const{
    return position.x;
}

int Figure::getY() const{
    return position.y;
}

void FSquare::findOwnCoord()
{
    position.x += (200 - sideSize) / 2;
    position.y += (200 - sideSize) / 2;
}

double FSquare::findArea()
{
    return sideSize*sideSize;
}

double FSquare::findPerimeter()
{
    return sideSize*4;
}

double FSquare::findRadiusOfInCircle()
{
    return sideSize / 2;
}

double FSquare::findRadiusOfOutCircle()
{
    return sideSize * (sqrt(2)/2.0);
}

int FSquare::getSideSize() const
{
    return sideSize;
}

int FRectangle::getHeight() const
{
    return height;
}

void FRectangle::findOwnCoord()
{
    position.x += (200 - width) / 2;
    position.y += (200 - height) / 2;
}

double FRectangle::findArea()
{
    return width*height;
}

double FRectangle::findPerimeter()
{
    return width*2 + height*2;
}

double FRectangle::findRadiusOfOutCircle()
{
    return (sqrt(width*width + height*height)/2.0);
}

int FRectangle::getWidth() const
{
    return width;
}

void FCircle::findOwnCoord()
{
    position.x += (200 - diameter) / 2;
    position.y += (200 - diameter) / 2;
}

double FCircle::findArea()
{
    return pow(diameter/2.0, 2) * M_PI;
}

double FCircle::findPerimeter()
{
    return diameter * 2 * M_PI;
}

int FCircle::getDiameter() const
{
    return diameter;
}

void FTriangle::findOwnCoord()
{
    point1.x += position.x;
    point1.y += position.y;
    point2.x += position.x;
    point2.y += position.y;
    point3.x += position.x;
    point3.y += position.y;
}

double FTriangle::findArea()
{
    double sideA = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
    double sideB = sqrt(pow((point2.x - point3.x), 2) + pow((point2.y - point3.y), 2));
    double sideC = sqrt(pow((point1.x - point3.x), 2) + pow((point1.y - point3.y), 2));
    double p = (sideA + sideB + sideC) / 2.0;
    return sqrt(p*(p - sideA)*(p - sideB)*(p - sideC));
}

double FTriangle::findPerimeter()
{
    return side1 + side2 + side3;
}

double FTriangle::findRadiusOfInCircle()
{
    return this->findArea()/((side1+side2+side3)/2);
}

double FTriangle::findRadiusOfOutCircle()
{
    return (side1*side2*side3)/(4*this->findArea());
}

double FTriangle::findMiddleLine()
{
    if (side1 >= side2 && side1 >= side3) return side1/2.0;
    if (side2 >= side1 && side2 >= side3) return side2/2.0;
    if (side3 >= side1 && side3 >= side2) return side3/2.0;
}

int FTriangle::getX1() const
{
    return point1.x;
}

int FTriangle::getX2() const
{
    return point2.x;
}

int FTriangle::getX3() const
{
    return point3.x;
}

int FTriangle::getY1() const
{
    return point1.y;
}

int FTriangle::getY2() const
{
    return point2.y;
}

int FTriangle::getY3() const
{
    return point3.y;
}

double FTriangle::findAngle1()
{
    double k1 = acos(((side3*side3)+(side2*side2)-(side1*side1))/(2.*side2*side3));
    return (k1*180)/M_PI;
}

double FTriangle::findAngle2()
{
    double k2 = acos(((side1*side1)+(side3*side3)-(side2*side2))/(2.*side1*side3));
    return (k2*180)/M_PI;
}

double FTriangle::findAngle3()
{
    double k3 = acos(((side1*side1)+(side2*side2)-(side3*side3))/(2.*side1*side2));
    return (k3*180)/M_PI;
}

double FTriangle::getSide1() const
{
    return side1;
}

double FTriangle::getSide2() const
{
    return side2;
}

double FTriangle::getSide3() const
{
    return side3;
}

void FEllipse::findOwnCoord()
{
    position.x += (200 - width) / 2;
    position.y += (200 - height) / 2;
}

double FEllipse::findArea()
{
    return (width/2.0) * (height/2.0) * M_PI;
}

double FEllipse::findPerimeter()
{
    return 2 * M_PI * (sqrt(pow(width, 2) + pow(width, 2)));
}

int FEllipse::getHeight() const
{
    return height;
}

int FEllipse::getWidth() const
{
    return width;
}
