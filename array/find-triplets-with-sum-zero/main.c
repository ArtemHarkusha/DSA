#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"


// i am going to return an array of pointers
// every pointer leads to a triplet (array of 3 elements)
int ** findTripletsWithZeroSum(int arr[], int size, int * returnSize){

  // allocate memory for an array of pointers 
  // we will be allocating memory for member dynamically
  int resultSize = 1;
  int insertPos = 0;
  uint resizeFactor = 2;
  int ** result = (int **) malloc(resultSize * sizeof(int *));

  for (int i = 0; i < size - 2; i++){
    for (int j = i + 1; j < size - 1; j++){
      for(int k = j + 1; k < size; k++){
        if ((arr[i] + arr[j] + arr[k]) == 0){
           if (resultSize == insertPos){
             // need to resize
             resultSize = resultSize * resizeFactor;
             result = (int **) realloc(result, resultSize * sizeof(int *));
           }
           result[insertPos] = (int *) malloc(3 * sizeof(int));
           result[insertPos][0] = arr[i];
           result[insertPos][1] = arr[j];
           result[insertPos][2] = arr[k];
           insertPos++;
        }
      }
    } 
  }
 
 *returnSize = insertPos - 1;
 return result;
    
}


void main(){

  int arr[] = {0, -1, 2, -3, 1};
  int size = sizeof(arr)/sizeof(int);
  int returnSize = 0;
 
  int ** result = findTripletsWithZeroSum(arr, size, &returnSize);
  for (int i = 0; i <= returnSize; i++){
    printArr(result[i], 3);
    free(result[i]);
  }
  free(result);
  

}
