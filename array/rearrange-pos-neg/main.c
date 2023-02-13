#include <stdio.h>
#include "helpers.h"

void rearrangeArr(int * arr, int size){
    int i, p;

    p = 0;
    for (i = 0; i < size; i++){
        if (arr[i] >= 0 ){
            swap(&arr[i], &arr[p]);
            p++;
        }
    }

    for (i = 1; i < size; i+=2){
        if (p < size && arr[i] >= 0){
            swap(&arr[i], &arr[p]);
            p++;
        }else {
            break;
        }
    }    

}

void main(){ 
  int arr[] = {-9, 2, -3, -4, -5, -6, -7, -8, -1};

  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);
  rearrangeArr(arr, size);
  printf("--------------REARRANGED-------\n");
  printArr(arr, size);


}
