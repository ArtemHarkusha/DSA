#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

int * findNmostFrequent(int * arr, int size, int k){

  // can't be 0
  if (0 == k){
    return; 
  }
  
  // we can't return more than the array size
  if (k > size) {
   k = size; 
  }
  
  // a very simple map data structure.
  // [n][m]. n - number; m - frequency
  int (* simple_map)[1] = malloc(size * sizeof(* arr));
  memset(simple_map, 0b0, size * sizeof(* arr));

  for (int i = 0; i < size; i++){
    //printArr((int *)simple_map[i], 1);
    //printf("Printing[%d][0]: %d\n", i, simple_map[i][0]);
    simple_map[arr[i]][0] += 1;;
  }

  for (int i = 0; i < size; i++){
    printArr((int *)simple_map[i], 1);
    printf("Printing[%d][0]: %d\n", i, simple_map[i][0]);
  }
  
  return arr;

}

void main(){

  int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
  int size = sizeof(arr)/sizeof(arr[0]);
  int k = 2;

  printArr(arr, size);
  findNmostFrequent(arr, size, k);
  

}
