#ifndef CELL_H
#define CELL_H
#include"line.hpp"

class Cell {
  public:
    Cell(Line& _item, Cell* _next);
  private:
    Line item;
    Cell* next;
  friend class ConvexHull;
};


#endif