#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

void rearrange(int * arr, int size){

  // corner case
  if (size <= 1){
    //nothing to do
    return;
  }
  if (size == 2){
    // swap 2 el
    swap(&arr[0], &arr[1]);
    return;
  }
  
  // allocate mem for aux array
  int * aux_arr = (int*) malloc(size * sizeof(int));
  int first = 0;
  int last = size - 1;

  //to avoid branching let's use two cycles to fillout odd and even indecis 
  for (int i = 0; i < size; i = i + 2) {
    aux_arr[i] = arr[last];
    last--;
  }

  for (int i = 1; i < size; i = i + 2) {
    aux_arr[i] = arr[first];
    first++;
  }

  // rewrite initial array
  for (int i = 0; i < size; i++) {
    arr[i] = aux_arr[i];
  }
  
  // free memory
  free(aux_arr);

}


void main(){

  int arr[] =  {1, 2, 3, 4, 5, 6};
  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);

  rearrange(arr, size);

  printArr(arr, size);

}
