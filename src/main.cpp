#include<iostream>
#include<cstdio>
#include<cstring>
#include"mergesort.hpp"
#include"convex_hull.hpp"
#include"graham.hpp"

Line * Polar(Point* values, int num, Point& lowest){
  Line * calcPolar = new Line[num - 1];
  int k = 0;
  for(int i = 0; i<num; i++){
    if(lowest == values[i])
      continue;
    calcPolar[k] = Line(lowest, values[i]);
    std::cout<<calcPolar[k].getPolarAngle()<<"\n";
    k++;
  }
  std::cout<<'\n';
  return calcPolar;
}


Point* resize(Point* values, int& maxSize, int num){
  maxSize *= 10;
  Point* newArray = new Point[maxSize*10];
  for(int i = 0; i <= num; i++){
    newArray[i] = values[i];
  }
  return newArray;
}

bool isLowest(Point a, Point b){
  if(b.getY()< a.getY())
    return true;
  if(b.getY() == a.getY())
    return b.getX() < a.getX();
  return false;
}


int main()
{ 
  FILE *file;
  char buffer[100];
  int maxSize = 100;
  int num = 0, lowest = -1;
  double X, Y;
  file = fopen("/home/mak/repos/convex_hull/test.txt", "r");
  if(file == NULL){
    std::cout<<"File not found\n";
    return -1;
  }
  Point * points = new Point[maxSize];
  while(fgets(buffer, sizeof(buffer), file) != NULL){
    if(maxSize < num){
      Point * aux = points;
      points = resize(points, maxSize, num);
      delete [] aux;
    }
    int value = sscanf(buffer, "%le %le", &X, &Y);
    if(value != 2){
      std::cout<<"Getting "<<value<<" values in line "<<num<<", only two values per line is permited, aborting.\n";
      delete [] points;
      return -2;
    }
    points[num] = Point(X,Y);
    if(lowest == -1){
      lowest = num;
    }else if(isLowest(points[lowest], points[num])){
      lowest = num;
    }
    num++;
    memset(buffer, 0, sizeof(buffer));
  }
  std::cout<<points[lowest].getX()<<" "<< points[lowest].getY()<<'\n';
  Line * calcPolar = new Line[num - 1];
  calcPolar = Polar(points, num, points[lowest]);
  ConvexHull* CH = new ConvexHull;
  CH = graham(MergeSort,calcPolar,0, num-1);

  return 0;
}