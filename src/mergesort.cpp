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
  delete [] left;
  delete [] right;
  return result;
}



Line* MergeSort(Line* array, int size){
  if(size > 1){
    int mid = size / 2;
    int i;
    int sizeR = (size % 2 == 1) ? mid +1 : mid;
    Line *right = new Line[sizeR], *left = new Line[mid];
    for(i = 0; i < mid; i++){
      left[i] = array[i];
    }
    for(; i< size; i++){
      right[i-mid] = array[i];
    }
    delete [] array;
    left = MergeSort(left, mid);
    right = MergeSort(right, sizeR);
    return Merge(left,right, mid, sizeR);
  }
  return array;

}