#include <stdio.h>
#include "helpers.h"

void printArr(int * arr, int size){
 int i;
 for (i = 0; i < size; i++){
 	printf("%d ", * (arr + i));
 }
 printf("\n");
}

void swap(int * a, int * b){
    int tmp = * a;
    * a = * b;
    * b = tmp;
}
