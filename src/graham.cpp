#include"graham.hpp"

// Function to calculate the polar angles of points with respect to the lowest point
Line * polarAngle(Point* values, int num, Point& lowest){
  Line * calcPolar = new Line[num - 1];
  int k = 0;
  for(int i = 0; i<num; i++){
    if(lowest == values[i])
      continue;
    calcPolar[k] = Line(lowest, values[i]); // Calculate the line representing the polar angle between the lowest point and each point (excluding the lowest point)
    k++;
  }
  return calcPolar; // Return the array of lines representing the polar angles
}

// Main Graham's algorithm function
ConvexHull * graham(Line* (*sortAlg)(Line*, int), Point * values, int size, Point& lowest){
  Line * calcPolar = polarAngle(values, size, lowest); // Calculate the polar angles of the points
  size -= 1; // Reduce the size to account for the lowest point
  Line * sorted = sortAlg(calcPolar, size); // Sort the lines based on the provided sorting algorithm
  if(size < 3){
    std::cout<<"empty convex hull\n"; // Print a message if the size is less than 3, indicating an empty convex hull
    return 0; // Return null pointer
  }
  ConvexHull* polygon = new ConvexHull(); // Create a new ConvexHull object
  polygon->stackLine(Line(sorted[0].getA(),sorted[0].getB())); // Add the first line to the ConvexHull stack
  polygon->stackLine(Line(sorted[0].getB(),sorted[1].getB())); // Add the second line to the ConvexHull stack

  for(int i = 2; i<size; i++){
    Line test = sorted[i];
    while(!polygon->isAntiClockWise(Line(polygon->getTop().getB(),test.getB()))) // Check if the current line is in an anticlockwise direction with respect to the top line in the stack
      polygon->unstack(); // Remove lines from the stack until the current line is in an anticlockwise direction
    polygon->stackLine(Line(polygon->getTop().getB(),test.getB())); // Add the current line to the ConvexHull stack
  }
  delete [] sorted; // Delete the dynamically allocated array of sorted lines
  return polygon; // Return the ConvexHull object
}