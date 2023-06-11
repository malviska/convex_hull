#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H
#include"line.hpp"
#include"cell.hpp"

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