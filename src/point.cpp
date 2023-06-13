#include"point.hpp"

// Default constructor
Point::Point(){};

// Constructor with X and Y coordinates
Point::Point(double _X, double _Y){
  X = _X;
  Y = _Y;
}

// Getter for X coordinate
int Point::getX(){
  return X;
}

// Getter for Y coordinate
int Point::getY(){
  return Y;
}

// Overloaded equality operator
bool Point::operator==(const Point& other){
  return (X == other.X) && (Y == other.Y); 
}