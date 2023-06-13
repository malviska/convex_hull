#include<iostream>
#include<cstdio>
#include<cstring>
#include"mergesort.hpp"
#include"convex_hull.hpp"
#include"graham.hpp"
#include"jarvis.hpp"
#include"insertionsort.hpp"
#include"radixsort.hpp"
#include <sys/resource.h>
#include <sys/time.h>

// Function to resize the array of points
Point* resize(Point* values, int maxSize, int num){
  Point* newArray = new Point[maxSize];
  for(int i = 0; i < num; i++){
    newArray[i] = values[i];
  }
  delete [] values;
  return newArray;
}


// Function to determine if point a is lower than point b
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
  char buffer[200];
  char filename[100];
  char comand[100];
  int maxSize = 100;
  int num = 0, lowest = -1;
  double X, Y;
  
  // Read command and filename from input
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%s %s", comand, filename);
  memset(buffer, 0, sizeof(buffer));

  // Open file for reading
  file = fopen(filename, "r");
  if(file == NULL){
    std::cout<<"File not found\n";
    return -1;
  }
  Point * points = new Point[maxSize];

  // Read points from the file
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
    }else if(isLowest(points[lowest], points[num])){
      lowest = num;
    }
    num++;
    memset(buffer, 0, sizeof(buffer));
  }
  struct rusage resources;
  int rc = getrusage(RUSAGE_SELF, &resources);

  if (rc != 0) {
    perror("getrusage failed");
    return 1;
  }

  long int utimeStart = resources.ru_utime.tv_usec;
  long int stimeStart = resources.ru_stime.tv_usec;

  // Execute the first convex hull algorithm (graham with MergeSort)
  ConvexHull* CH = graham(MergeSort, points, num, points[lowest]);

  rc = getrusage(RUSAGE_SELF, &resources);
  if (rc != 0) {
    perror("getrusage failed");
    return 1;
  }

  long int utimeEnd = resources.ru_utime.tv_usec;
  long int stimeEnd = resources.ru_stime.tv_usec;
  long int utime = utimeEnd - utimeStart;
  long int stime = stimeEnd - stimeStart;
  long int grahamMerge = utime + stime;

  CH->print();

  utimeStart = resources.ru_utime.tv_sec * 1000000 + resources.ru_utime.tv_usec;
  stimeStart = resources.ru_stime.tv_sec * 1000000 + resources.ru_stime.tv_usec;

  // Execute the second convex hull algorithm (jarvis)
  ConvexHull* CHJ = jarvis(points, num, points[lowest]);

  rc = getrusage(RUSAGE_SELF, &resources);
  if (rc != 0) {
    perror("getrusage failed");
    return 1;
  }

  utimeEnd = resources.ru_utime.tv_sec * 1000000 + resources.ru_utime.tv_usec;
  stimeEnd = resources.ru_stime.tv_sec * 1000000 + resources.ru_stime.tv_usec;
  utime = utimeEnd - utimeStart;
  stime = stimeEnd - stimeStart;
  long int jarvis = utime + stime;

  utimeStart = resources.ru_utime.tv_sec * 1000000 + resources.ru_utime.tv_usec;
  stimeStart = resources.ru_stime.tv_sec * 1000000 + resources.ru_stime.tv_usec;

  // Execute the third convex hull algorithm (graham with InsertionSort)
  ConvexHull* CH2 = graham(InsertionSort, points, num, points[lowest]);

  rc = getrusage(RUSAGE_SELF, &resources);
  if (rc != 0) {
    perror("getrusage failed");
    return 1;
  }

  utimeEnd = resources.ru_utime.tv_sec * 1000000 + resources.ru_utime.tv_usec;
  stimeEnd = resources.ru_stime.tv_sec * 1000000 + resources.ru_stime.tv_usec;
  utime = utimeEnd - utimeStart;
  stime = stimeEnd - stimeStart;
  long int grahamInsertion = utime + stime;

  utimeStart = resources.ru_utime.tv_sec * 1000000 + resources.ru_utime.tv_usec;
  stimeStart = resources.ru_stime.tv_sec * 1000000 + resources.ru_stime.tv_usec;

  // Execute the fourth convex hull algorithm (graham with RadixSort)
  ConvexHull* CH3 = graham(RadixSort, points, num, points[lowest]);

  rc = getrusage(RUSAGE_SELF, &resources);
  if (rc != 0) {
    perror("getrusage failed");
    return 1;
  }

  utimeEnd = resources.ru_utime.tv_sec * 1000000 + resources.ru_utime.tv_usec;
  stimeEnd = resources.ru_stime.tv_sec * 1000000 + resources.ru_stime.tv_usec;
  utime = utimeEnd - utimeStart;
  stime = stimeEnd - stimeStart;
  long int grahamRadix = utime + stime;

  //print results in microsseconds
  std::cout <<
    "\nGRAHAM+MERGESORT: " << grahamMerge << " microsseconds"<<
    "\nGRAHAM+INSERTIONSORT: " << grahamInsertion <<  " microsseconds"<<
    "\nGRAHAM+LINEAR: " << grahamRadix << " microsseconds"<<
    "\nJARVIS: " << jarvis <<  " microsseconds\n";

  delete [] points;
  delete CH;
  delete CHJ;
  delete CH2;
  delete CH3;
  return 0;
}