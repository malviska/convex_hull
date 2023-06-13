#include"radixsort.hpp"

// Function to extract a specific bit from a floating-point value
// I had to cast to int to work with radix sort...
int digit(double val, int bitNum) {
  int comp = 1 << bitNum;
  int cast = static_cast<int>(val * 1000);
  int result = cast & comp;
  return result;
}

// Partition function used in the Radix Sort algorithm
void Particao(int Esq, int Dir, int* i, int* j, Line* A, int bitNum) {
  Line x, w;
  *i = Esq;
  *j = Dir;
  do {
    // Move the left pointer (*i) until a 0 bit is encountered
    while (digit(A[*i].getPolarAngle(), bitNum) == 0 && (*i < *j))
      (*i)++;
    // Move the right pointer (*j) until a 1 bit is encountered
    while (digit(A[*j].getPolarAngle(), bitNum) == 1 && (*j > *i))
      (*j)--;
    // Swap the lines if the left pointer is still smaller than the right pointer
    if (*i < *j) {
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i < *j);
}

// Recursive sorting function used in the Radix Sort algorithm
void Ordena(int Esq, int Dir, Line* A, int bitNum) {
  // Base case: if the subarray has one element or the bit number is negative, return
  if (Esq >= Dir || bitNum < 0)
    return;
  int i, j;
  // Partition the subarray using the current bit number
  Particao(Esq, Dir, &i, &j, A, bitNum);
  // Recursively sort the subarrays formed by the partition
  Ordena(Esq, j, A, bitNum - 1);
  Ordena(i, Dir, A, bitNum - 1);
}

// Radix Sort function
Line* RadixSort(Line* array, int size) {
  // Sort the array using Radix Sort with 11 bits (from bit 10 to bit 0)
  Ordena(0, size - 1, array, 11);
  return array;
}