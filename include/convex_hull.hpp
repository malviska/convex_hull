#include"line.hpp"
#include"cell.hpp"

#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

class ConvexHull {
  public:
    ConvexHull();
    ~ConvexHull();

    void stackLine(Line);
    Line getTop();
    Line unstack();
    bool empty();
    void clean();
  private:
    Cell* top;
    int size;
};



#endif