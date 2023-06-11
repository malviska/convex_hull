#include"graham.hpp"


ConvexHull * graham(Line* (*sortAlg)(Line*, int, int), Line * values, int first, int size){
  Line * sorted = sortAlg(values, first, size);
  if(size < 3){
    std::cout<<"empty convex hull\n";
    return 0;
  }
  ConvexHull* polygon = new ConvexHull();
  polygon->stackLine(sorted[1]);
  polygon->stackLine(sorted[2]);
  polygon->stackLine(sorted[3]);

  for(int i = 4; i<size; i++){
    Line test = sorted[i];
    while(Line(polygon->getTop().getB(), test.getB()).getPolarAngle() < 0)
      polygon->unstack();
    polygon->stackLine(test);
  }
  return polygon;
}

