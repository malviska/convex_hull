#include"line.hpp"
#include"cell.hpp"
#include<iostream>

#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

class ConvexHull {
  public:
    ConvexHull();
    ~ConvexHull();

    void stackLine(Line);
    Line getTop();
    Line unstack();
    bool isAntiClockWise(Line);
    bool empty();
    void clean();
    void print();

  private:
    Cell* top;
    int size;
};



#endif