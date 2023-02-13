#include <stdio.h>
#include "helpers.h"

// own solution
void pushZerosToTheEndA(int * arr, int size){
  
  printf("Using own implementation.\n");
  // find the first non-zero element starting from the end
  unsigned int lastNonZero = size - 1;

  while ((arr[lastNonZero] == 0) && (lastNonZero != 0)) {
    lastNonZero--;
  }

  // if the first non-zero starting from the end has index 0 - the array contains only zeros
  if (lastNonZero == 0){
    return; 
  }

  // let's travers the left elements and push zeros to the end
  for (int i = 0;  i < lastNonZero; i++){
    if (arr[i] == 0){
      swap(&arr[i], &arr[lastNonZero]); 
      lastNonZero--;
      while ((arr[lastNonZero] == 0) && (lastNonZero != 0)) {
        lastNonZero--;
      }
    } 
  }

  printf("Last non-zero: %i\n", lastNonZero); 
 
}

// geek for geeks solution
// instead of moving all zeros to the end, we will be moving all non-zeros to the beginnig
void pushZerosToTheEndB(int * arr, int size){

  printf("Using GeekForGeeks implementation.\n");
  int firstNonZero = 0;
  for (int i = 0; i < size; i++){
    if (arr[i] != 0){
      swap(&arr[i], &arr[firstNonZero]);
      firstNonZero++;
    }
  }

}

void main(){

  int arr[] = { 0, 11, 4, 0, 8, 0 };
  //int arr[] = { 1, 0, 0, 0 };
  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);
#if defined USE_OWN_IMPLEMENTATION
  pushZerosToTheEndA(arr, size);
#else
  pushZerosToTheEndB(arr, size);
#endif

  printArr(arr, size);

}
