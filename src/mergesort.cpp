#include"mergesort.hpp"

// Merge two sorted arrays into a single sorted array
Line* Merge(Line* left, Line* right, int nL, int nR){
  Line* result = new Line[nL+nR]; // Create a new array to store the merged result
  int i = 0, j = 0, k =0; // Initialize indices for left, right, and result arrays

  // Merge the arrays by comparing elements from left and right arrays
  while(i < nL && j < nR){
    if(left[i] < right[j]){
      result[k] = left[i];
      i++;
    } else {
      result[k] = right[j];
      j++;
    }
    k++;
  }

  // Copy any remaining elements from the left array
  if(k < nL+nR){
    for(; i < nL; i++){
      result[k] = left[i];
      k++;
    }
  }

  // Copy any remaining elements from the right array
  for(; j < nR; j++){
    result[k] = right[j];
    k++;
  }

  delete [] left; // Free memory allocated for the left array
  delete [] right; // Free memory allocated for the right array

  return result; // Return the merged result
}

// Merge sort algorithm
Line* MergeSort(Line* array, int size){
  if(size > 1){
    int mid = size / 2; // Calculate the midpoint of the array
    int i;
    int sizeR = (size % 2 == 1) ? mid + 1 : mid; // Calculate the size of the right array

    // Create the left and right arrays
    Line* right = new Line[sizeR];
    Line* left = new Line[mid];

    // Copy elements to the left array
    for(i = 0; i < mid; i++){
      left[i] = array[i];
    }

    // Copy elements to the right array
    for(; i < size; i++){
      right[i - mid] = array[i];
    }

    delete [] array; // Free memory allocated for the original array

    // Recursively apply MergeSort on the left and right arrays
    left = MergeSort(left, mid);
    right = MergeSort(right, sizeR);

    // Merge the sorted left and right arrays
    return Merge(left, right, mid, sizeR);
  }

  return array; // Return the sorted array (base case: size <= 1)
}