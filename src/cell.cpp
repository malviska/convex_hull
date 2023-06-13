#include"cell.hpp"
//cell helper to stack in convex_hull
Cell::Cell(Line& _line, Cell* _next){
  this->item = Line();
  this->item = _line;
  this->next = _next;
}