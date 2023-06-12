#include"graham.hpp"


ConvexHull * graham(Line* (*sortAlg)(Line*, int), Line * values, int size){
  Line * sorted = sortAlg(values, size);
  if(size < 3){
    std::cout<<"empty convex hull\n";
    return 0;
  }
  ConvexHull* polygon = new ConvexHull();
  polygon->stackLine(Line(sorted[0].getA(),sorted[0].getB()));
  polygon->stackLine(Line(sorted[0].getB(),sorted[1].getB()));

  for(int i = 2; i<size; i++){
    Line test = sorted[i];
    while(!polygon->isAntiClockWise(Line(polygon->getTop().getB(),test.getB())))
      polygon->unstack();
    polygon->stackLine(Line(polygon->getTop().getB(),test.getB()));
  }
  delete [] sorted;
  return polygon;
}
