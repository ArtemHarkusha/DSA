#include <stdio.h>
#include <limits.h>
#include "helpers.h"

void findNlargest(int * arr, int * result, int size, int n){
  
  int largest;
  int largest_index = 0;
  for (int i = 0; i <= n; i++){
    largest = INT_MIN;
    for (int j = 0; j < size; j++){
      if (arr[j] > largest){
        largest = arr[j];
        largest_index = j;
      } 
    }
    result[i] = largest;
    arr[largest_index] = INT_MIN;
  }
  
}

void main(){

  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr)/sizeof(int);
  int nLargest = 3;
  // aka buf[] to store the result
  int result[nLargest];

  printArr(arr, size);
  //call processing func
  findNlargest(arr, result, size, nLargest);
  printArr(result, nLargest);

}
