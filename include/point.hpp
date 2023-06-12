#ifndef POINT_H
#define POINT_H

class Point 
{
  public:
    int getX();
    int getY();
    Point(double x, double y);
    Point();
    bool operator==(const Point&);
  private:
    double X;
    double Y;
};  



#endif