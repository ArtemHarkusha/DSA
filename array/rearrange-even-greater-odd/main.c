#include <stdio.h>
#include "helpers.h"

void rearrange(int * arr, int size){

    for (int i = 1; i < size; i++ ){
      // i is even
      if (i % 2 == 0){
        if (arr[i] < arr[i - 1]) {
          swap(&arr[i], &arr[i - 1]);
        }
      }

      // i is odd
      if (i % 2 != 0) {
        if (arr[i] > arr[i - 1]) {
          swap(&arr[i], &arr[i - 1]);
        }
      }
    }

}


void main(){
  int arr[] = {7, 23, 6, 1, 3, 2, 14, 58};
  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);

  rearrange(arr, size);

  printArr(arr, size);

}
