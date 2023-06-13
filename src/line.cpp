#include"line.hpp"

// Default constructor
Line::Line(){
  polarAngle = 5; // Initialize the polar angle to a default value (Absurd impossible Value)
}

// Custom constructor
Line::Line(Point _A, Point _B){
  a = _A; // Set point A of the line
  b = _B; // Set point B of the line
  calculePolarAngle(); // Calculate the polar angle of the line
}

// Calculate the polar angle of the line
void Line::calculePolarAngle(){
  // Calculate the polar angle using trigonometric functions
  double _polarAngle = (b.getY()- a.getY())/(sqrt(pow(b.getX() - a.getX(), 2)+pow(b.getY()- a.getY(), 2)));
  double cosAngle = (b.getX()- a.getX())/(sqrt(pow(b.getX() - a.getX(), 2)+pow(b.getY()- a.getY(), 2)));

  // Adjust the polar angle based on the quadrant and cosine angle
  if(_polarAngle > 0 && cosAngle < 0){
    _polarAngle = 2 - _polarAngle;
  }else if(_polarAngle < 0 && cosAngle < 0){
    _polarAngle = 2 - _polarAngle;
  }else if(_polarAngle < 0 && cosAngle > 0){
    _polarAngle = 4 + _polarAngle;
  }else if(cosAngle == 0 && _polarAngle == -1){
    _polarAngle = 3;
  }

  polarAngle = _polarAngle; // Store the calculated polar angle
}

// Get the polar angle of the line
double Line::getPolarAngle(){
  return polarAngle;
}

// Get point A of the line
Point Line::getA(){
  return a;
}

// Get point B of the line
Point Line::getB(){
  return b;
}

// Comparison operator < (used for sorting lines based on polar angle)
bool Line::operator<(const Line& value){
  return polarAngle < value.polarAngle;
}

// Comparison operator > (used for sorting lines based on polar angle)
bool Line::operator>(const Line& value){
  return polarAngle > value.polarAngle;
}

// Get the x-coordinate of point A
double Line::getX1(){
  return a.getX();
}

// Get the x-coordinate of point B
double Line::getX2(){
  return b.getX();
}

// Get the y-coordinate of point A
double Line::getY1(){
  return a.getY();
}

// Get the y-coordinate of point B
double Line::getY2(){
  return b.getY();
}



