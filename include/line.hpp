#ifndef LINE_H
#define LINE_H

#include"point.hpp"

class Line 
{
  public:
    Line(){}
    Line(Point a, Point b);
    Point getB();
    Point getA();
    int getPolarAngle();
    bool operator<(const Line& value);
    bool operator>(const Line& value);
  private:
    Point a;
    Point b;
    int polarAngle;
    void calculePolarAngle();
};





#endif