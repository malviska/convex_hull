#include<iostream>
#include<cstdio>
#include<cstring>
#include"mergesort.hpp"
#include"convex_hull.hpp"
#include"graham.hpp"
#include"jarvis.hpp"

Point* resize(Point* values, int maxSize, int num){
  Point* newArray = new Point[maxSize];
  for(int i = 0; i < num; i++){
    newArray[i] = values[i];
  }
  delete [] values;
  return newArray;
}

bool isBiggest(Point a, Point b){
  if(b.getY()> a.getY())
    return true;
  if(b.getY() == a.getY())
    return b.getX() > a.getX();
  return false;
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
  int num = 0, lowest = -1, biggest = -1;
  double X, Y;
  file = fopen("/home/mak/repos/convex_hull/test.txt", "r");
  if(file == NULL){
    std::cout<<"File not found\n";
    return -1;
  }
  Point * points = new Point[maxSize];
  while(fgets(buffer, sizeof(buffer), file) != NULL){
    if(maxSize <= num){
      maxSize *= 10;
      points = resize(points, maxSize, num);
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
      biggest = num;
    }else if(isLowest(points[lowest], points[num])){
      lowest = num;
    }else if(isBiggest(points[biggest], points[num])){
      biggest = num;
    }
    num++;
    memset(buffer, 0, sizeof(buffer));
  }
  //ConvexHull * CH = graham(MergeSort,points,num, points[lowest]);
  ConvexHull * CH = jarvis(points, num, points[lowest], points[biggest]);
  CH->print();
  delete [] points;
  delete CH;
  return 0;
}