#include <stdio.h>
#include "helpers.h"

void rearrangeArr(int * arr, int size){
    int i, tmp1, tmp2;
    for (i = 0; i < size; i++){
        if (arr[i] != -1 && arr[i] != i){
            tmp1 = arr[i];
            while (arr[tmp1] != -1 && arr[tmp1] != tmp1){
                tmp2 = arr[tmp1];
                arr[tmp1] = tmp1;
                tmp1 = tmp2;
            }
            
            arr[tmp1] = tmp1;

            if (arr[i] != i){
               arr[i] = -1; 
            }
        }
    }

}

void main(){ 
  //int arr[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
  //            11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
  
  int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};

  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);
  rearrangeArr(arr, size);
  printf("--------------REARRANGED-------\n");
  printArr(arr, size);


}
