#include"graham.hpp"

Line * polarAngle(Point* values, int num, Point& lowest){
  Line * calcPolar = new Line[num - 1];
  int k = 0;
  for(int i = 0; i<num; i++){
    if(lowest == values[i])
      continue;
    calcPolar[k] = Line(lowest, values[i]);
    k++;
  }
  return calcPolar;
}

ConvexHull * graham(Line* (*sortAlg)(Line*, int), Point * values, int size, Point& lowest){
  Line * calcPolar = polarAngle(values, size, lowest);
  size -= 1;
  Line * sorted = sortAlg(calcPolar, size);
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
