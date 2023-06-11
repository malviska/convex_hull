#include"cell.hpp"

Cell::Cell(Line& _line, Cell* _next){
  item = _line;
  next = _next;
}