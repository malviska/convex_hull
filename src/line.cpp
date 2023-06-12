#include"line.hpp"

Line::Line(Point _A, Point _B){
  a = _A;
  b = _B;
  calculePolarAngle();
}

void Line::calculePolarAngle(){
  double _polarAngle = (b.getY()- a.getY())/(sqrt(pow(b.getX() - a.getX(), 2)+pow(b.getY()- a.getY(), 2)));
  if(a.getX() > b.getX()){
    _polarAngle = 2 - _polarAngle;
  }
  polarAngle = _polarAngle;
}

double Line::getPolarAngle(){
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

double Line::getX1(){
  return a.getX();
}

double Line::getX2(){
  return b.getX();
}

double Line::getY1(){
  return a.getY();
}

double Line::getY2(){
  return b.getY();
}




