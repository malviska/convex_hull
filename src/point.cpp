#include"point.hpp"

Point::Point(){};

Point::Point(double _X, double _Y){
  X = _X;
  Y = _Y;
}

int Point::getX(){
  return X;
}

int Point::getY(){
  return Y;
}

bool Point::operator==(const Point& other){
  return (X == other.X) && (Y == other.Y); 
}
