#include"point.hpp"

Point::Point(){};

Point::Point(int _X, int _Y){
  X = _X;
  Y = _Y;
}

int Point::getX(){
  return X;
}

int Point::getY(){
  return Y;
}