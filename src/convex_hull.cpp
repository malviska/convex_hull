#include"convex_hull.hpp"
#include<iostream>

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

bool ConvexHull::isAntiClockWise(Line value){
  double result = (top->item.getX2()-top->item.getX1())*(value.getY2()- value.getY1()) - (top->item.getY2() - top->item.getY1())*(value.getX2()-value.getX1());
  std::cout<<result<<"\n";
  return result > 0;
}