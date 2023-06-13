#include<cmath>
#include"point.hpp"

#ifndef LINE_H
#define LINE_H

class Line 
{
  public:
    Line();
    Line(Point a, Point b);
    Point getB();
    Point getA();
    double getPolarAngle();
    double getX1();
    double getX2();
    double getY1();
    double getY2();
    bool operator<(const Line& value);
    bool operator>(const Line& value);
  private:
    Point a;
    Point b;
    double polarAngle;
    void calculePolarAngle();
};





#endif