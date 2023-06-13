#include"convex_hull.hpp"

// Default constructor
ConvexHull::ConvexHull(){
  top = nullptr;
  size = 0;
}

// Destructor
ConvexHull::~ConvexHull(){
  clean();
}

// Add a line to the stack
void ConvexHull::stackLine(Line line){
  Cell * cell = new Cell(line, top); // Create a new cell with the given line
  top = cell; // Make the new cell the top of the stack
  size++; // Increase the size of the stack
}

// Remove and return the top line from the stack
Line ConvexHull::unstack(){
  if(size == 0){
    throw "Empty polygon"; // Throw an exception if the stack is empty
  }
  Line aux = top->item; // Store the line from the top of the stack
  Cell *p = top; // Store the pointer to the top cell
  top = top->next; // Make the next cell the new top of the stack
  delete p; // Delete the old top cell
  size--; // Decrease the size of the stack

  return aux; // Return the stored line
}

// Check if the stack is empty
bool ConvexHull::empty(){
  return size == 0; // Return true if the size is 0, indicating an empty stack
}

// Remove all lines from the stack
void ConvexHull::clean(){
  while(!empty()){
    unstack(); // Remove the top line until the stack is empty
  }
}

// Get the top line from the stack
Line ConvexHull::getTop(){
  return top->item; // Return the line stored in the top cell
}

// Check if a given line is in an anticlockwise direction with respect to the top line of the stack
bool ConvexHull::isAntiClockWise(Line value){
  double result = (top->item.getX2()-top->item.getX1())*(value.getY2()- value.getY1()) - (top->item.getY2() - top->item.getY1())*(value.getX2()-value.getX1());
  
  return result > 0; // Return true if the result is greater than 0, indicating an anticlockwise direction
}

// Print the lines in the stack, representing the convex hull
void ConvexHull::print(){
  std::cout<<"FECHO CONVEXO:\n";
  Line value = Line();
  int max = size;
  ConvexHull invert = ConvexHull();
  for(int i = 0; i < max; i++){
    if(empty())
      break;
    value = unstack(); // Get and remove the next line from the stack
    invert.stackLine(value);
  }
  value = invert.unstack(); // Get and remove the top line from the stack
  std::cout<<value.getX1()<<" "<<value.getY1()<<'\n'; // Print the coordinates of the endpoint of the top line
  for(int i = 0; i < max; i++){
    std::cout<<value.getX2()<<" "<<value.getY2()<<'\n'; // Print the coordinates of the start point of the line
    if(invert.empty())
      break;
    value = invert.unstack(); // Get and remove the next line from the stack
  }
}