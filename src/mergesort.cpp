#include"mergesort.hpp"

Line* Merge(Line* left, Line* right, int nL, int nR){
  Line* result = new Line[nL+nR];
  int i = 0, j = 0, k =0;
  while(i < nL && j< nR){
    if(left[i] < right[j]){
      result[k] = left[i];
      i++;
    } else {
      result[k] = right[j];
      j++;
    }
    k++;
  }
  if(k< nL+nR){
    for(; i<nL; i++){
      result[k] = left[i];
      k++;
    }
    for(;j<nR; j++){
      result[k] = right[j];
      k++;
    }
  }
  return result;
}



Line* MergeSort(Line* array, int first, int size){
  if(size > first){
    int mid = (size - first)/2;
    int i;
    Line *right, *left;
    for(i = 0; i < mid; i++){
      left[i] = array[i];
    }
    for(; i< size; i++){
      right[i] = array[i];
    }
    delete array;
    left = MergeSort(left,first, mid);
    right = MergeSort(right, mid, size);
    int sizeR = (size % 2 == 1) ? mid +1 : mid;
    return Merge(left,right, mid, sizeR);
  }

}