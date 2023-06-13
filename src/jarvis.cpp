#include"jarvis.hpp"

// Jarvis algorithm function
ConvexHull* jarvis(Point* values, int size, Point& lowest){
  ConvexHull* polygon = new ConvexHull(); // Create a new ConvexHull object
  double minValue = 0; // Initialize the minimum polar angle value
  Line val; // Variable to store lines
  Point Vertex = lowest; // Initialize the starting vertex as the lowest point

  while(true){
    Point* candidate = nullptr; // Pointer to store the candidate point
    for(int i = 0; i < size; i++){
      if(values[i] == Vertex) // Skip the lowest point
        continue;
      if(candidate == nullptr){
        val = Line(Vertex, values[i]); // Calculate the line between the current vertex and a point
        if(val.getPolarAngle() > minValue)
          candidate = &values[i]; // Set the current point as the candidate
        continue;
      }
      Line valdisney = Line(Vertex, values[i]); // Calculate the line between the current vertex and a point
      if(valdisney.getPolarAngle() > minValue && valdisney < val){
        candidate = &values[i]; // Update the candidate if the line has a greater polar angle and is smaller than the previous candidate
        val = valdisney; // Update the line value
      }
    }
    if(candidate == &lowest)
      break; // Break the loop if the lowest point is encountered again
    Line line = Line(Vertex, *candidate); // Create a line between the current vertex and the candidate point
    minValue = line.getPolarAngle(); // Update the minimum polar angle value
    polygon->stackLine(line); // Add the line to the ConvexHull stack
    Vertex = *candidate; // Update the current vertex to the candidate point
  }

  return polygon; // Return the ConvexHull object
}
