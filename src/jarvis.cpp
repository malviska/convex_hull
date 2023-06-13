#include"jarvis.hpp"


ConvexHull* jarvis(Point* values, int size, Point& lowest, Point& biggest){
  ConvexHull* polygon = new ConvexHull();
  double sign = 1;
  Line val;
  Point Vertex = lowest;
  while(true){
    Point* candidate = nullptr;
    for(int i = 0; i< size; i++){
      if(values[i] == Vertex)
        continue;
      if(candidate == nullptr){
        candidate = &values[i];
        val = Line(Vertex, *candidate);
        continue;
      }
      Line valdisney = Line(Vertex, values[i]);
      if((sign*valdisney.angle() > 0.0) && (sign*valdisney.angle() < sign*val.angle())){
        candidate = &values[i];
        val = valdisney;
      }
    }
    if(candidate == &biggest) sign = -1;
    if(candidate == &lowest) break;
    Line line = Line(Vertex, *candidate);
    polygon->stackLine(line);
    Vertex = *candidate;
    }
    return polygon;
  }
