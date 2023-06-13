#include"line.hpp"

Line::Line(){
  polarAngle = 5;
}

Line::Line(Point _A, Point _B){
  a = _A;
  b = _B;
  calculePolarAngle();
}

void Line::calculePolarAngle(){
  double _polarAngle = (b.getY()- a.getY())/(sqrt(pow(b.getX() - a.getX(), 2)+pow(b.getY()- a.getY(), 2)));
  double cosAngle = (b.getX()- a.getX())/(sqrt(pow(b.getX() - a.getX(), 2)+pow(b.getY()- a.getY(), 2)));
  if(_polarAngle > 0 && cosAngle < 0){
    _polarAngle = 2 - _polarAngle;
  }else if(_polarAngle < 0 && cosAngle < 0){
    _polarAngle = 2 - _polarAngle;
  }else if(_polarAngle < 0 && cosAngle > 0){
    _polarAngle = 4 + _polarAngle;
  }else if(cosAngle == 0 && _polarAngle == -1){
    _polarAngle = 3;
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




