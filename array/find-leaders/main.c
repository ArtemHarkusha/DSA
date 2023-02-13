#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int * findLeaders(int arr[], int size, int * returnSize){

  int * answr = (int*) malloc(size * sizeof(int));
  answr[0] = arr[size - 1];
  unsigned int lastLeaderPosition = 0;
  for (int i = size - 2; i >= 0; i--){
    if (arr[i] > answr[lastLeaderPosition]){
      lastLeaderPosition++;
      answr[lastLeaderPosition] = arr[i];
    }
  }

  * returnSize = lastLeaderPosition + 1;
  return answr; 

}

void main(){

  int arr[] = {16, 17, 4, 3, 5, 2};
  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);
  int returnSize = 0;
  int * result = findLeaders(arr, size, &returnSize);
  printArr(result, returnSize);
  free(result);

}
