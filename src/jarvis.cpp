#include"jarvis.hpp"


ConvexHull* jarvis(Point* values, int size, Point& lowest){
  ConvexHull* polygon = new ConvexHull();
  double minValue = 0;
  Line val;
  Point Vertex = lowest;
  while(true){
    Point* candidate = nullptr;
    for(int i = 0; i< size; i++){
      if(values[i] == Vertex)
        continue;
      if(candidate == nullptr){
        val = Line(Vertex, values[i]);
        if(val.getPolarAngle()> minValue)
          candidate = &values[i];
        continue;
      }
      Line valdisney = Line(Vertex, values[i]);
      if(valdisney.getPolarAngle() > minValue && valdisney < val){
        candidate = &values[i];
        val = valdisney;
      }
    }
    if(candidate == &lowest) break;
    Line line = Line(Vertex, *candidate);
    minValue = line.getPolarAngle();
    polygon->stackLine(line);
    Vertex = *candidate;
    }
    return polygon;
  }
