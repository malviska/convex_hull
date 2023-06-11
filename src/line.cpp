#include"line.hpp"

Line::Line(Point _A, Point _B){
  a = _A;
  b = _B;
  calculePolarAngle();
}

void Line::calculePolarAngle(){
  int _polarAngle = a.getX() * b.getY() - a.getY() * b.getX();
  polarAngle = _polarAngle;
}

int Line::getPolarAngle(){
  return polarAngle;
}

Point Line::getA(){
  return a;
}

Point Line::getB(){
  return b;
}

bool Line::operator<(const Line& value){
  return polarAngle < value.polarAngle;
}

bool Line::operator>(const Line& value){
  return polarAngle > value.polarAngle;
}


