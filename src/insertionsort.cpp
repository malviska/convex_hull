#include"insertionsort.hpp"
//simple insertionsort
Line * InsertionSort(Line* array, int size){
  int i, j;
  Line aux;
  for(i = 1; i< size; i++){
    aux =array[i];
    j = i-1;
    while((j>=0) && aux < array[j]){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = aux;
  }
  return array;
}