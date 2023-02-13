#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

#define TRUE 1
#define FALSE 0

int * findUniqueMembers(int arr[], int size, int * returnSize){

  int * answr = (int*) malloc(size * sizeof(int));
  int pos = 0;
  uint unique = FALSE;

  for (int i = 0; i < size; i++){
    unique = TRUE;
    for (int j = i + 1; j < size; j++){
      if (arr[i] == arr[j]){
        unique = FALSE;
        break;
      }
    }
    if (TRUE == unique){
      answr[pos] = arr[i];
      pos++;
    }
  }

  * returnSize = pos + 1;
  return answr; 

}

void main(){

  int arr[] = {12, 10, 9, 45, 2, 10, 10, 45};
  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);
  int returnSize = 0;
  int * result = findUniqueMembers(arr, size, &returnSize);
  printArr(result, returnSize);
  free(result);

}
