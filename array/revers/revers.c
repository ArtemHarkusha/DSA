#include "stdio.h"

void printArr(int * arr, int size){
 int i;
 for (i = 0; i < size; i++){
 	printf("EL%d: %d\n", i + 1, * (arr + i));
 }
}


void reversArr(int * arr, int size){
    int tmp;
    int start = 0, end = size - 1;

    while (start < end) {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

void main(){
  int size = 5; 
  int arr[] = {10, 20, 30, 40, 50};
  //size = sizeof(arr)/sizeof(int);
  
  printArr(arr, size);

  
  printf("--------------REVERSED-------\n");

  reversArr(arr, size);
  printArr(arr, size);
}
