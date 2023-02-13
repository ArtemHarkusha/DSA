#include "stdio.h"

void printArr(int * arr, int size){
 int i;
 for (i = 0; i < size; i++){
 	printf("FUNC: %d\n", * (arr + i));
 }
}

void main(){
  int i;
  int arr[5] = {10, 20, 30, 40, 50};
  for (i=0; i<5; i++){
  	printf("ELEM: %d\n",arr[i]);
  }
  printf("Arr size: %d\n", (int)(sizeof(arr)));
  printf("Element size: %d\n", (int)(sizeof(arr[0])));
  printf("Element num: %d\n", (int)(sizeof(arr)/sizeof(arr[0])));
  printArr(arr, (int)(sizeof(arr)/sizeof(int)));
}
