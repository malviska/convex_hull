#include"convex_hull.hpp"

ConvexHull::ConvexHull(){
  top = nullptr;
  size = 0;
}

ConvexHull::~ConvexHull(){
  clean();
}

void ConvexHull::stackLine(Line line){
  Cell * cell = new Cell(line, top);
  top = cell;
  size++;
}

Line ConvexHull::unstack(){
  if(size == 0){
    throw "Empty polygon";
  }
  Line aux = top->item;
  Cell *p = top;
  top = top->next;
  delete p;
  size--;

  return aux;
}


bool ConvexHull::empty(){
  return size == 0;
}


void ConvexHull::clean(){
  while(!empty()){
    unstack();
  }
}

Line ConvexHull::getTop(){
  return top->item;
}