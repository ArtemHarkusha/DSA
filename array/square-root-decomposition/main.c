#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "helpers.h"

typedef struct {
  int block_size; 
  int * arr;
  int * square_root_sum;
  int * square_root_min;
} SQUARE_ROOT;

typedef enum {
  SUM,
  MIN
} QUERY;

void preprocess(SQUARE_ROOT *);
int query_sum(SQUARE_ROOT * obj, int, int);
int query_min(SQUARE_ROOT * obj, int, int);
int query(SQUARE_ROOT * obj, QUERY, int, int);

void preprocess(SQUARE_ROOT * obj){

  int sum, min;
  int offset = 0;
  for (int i = 0; i < obj->block_size; i++){
    sum = 0;
    min = INT_MAX;
    for (int j = 0; j < obj->block_size; j++){
      sum = sum + obj->arr[j + offset];
      if (min > obj->arr[j + offset]){
        min = obj->arr[j + offset];
      }
    }
    offset = offset + obj->block_size;
    obj->square_root_sum[i] = sum;
    obj->square_root_min[i] = min;
  }

}

int query(SQUARE_ROOT * obj, QUERY query, int start, int end) {

  switch (query){
  
    case SUM:
      return query_sum(obj, start, end);
      break;
    
    case MIN:
      return query_min(obj, start, end);
      break;
  }

}

int query_min(SQUARE_ROOT * obj, int start, int end){

 int min = INT_MAX;

 while (start < end && start % obj->block_size  != 0 && start != 0){
   if (min > obj->arr[start]){
    min = obj->arr[start];
   }
   start++;
 }

 while (start + obj->block_size - 1 <= end ){
   if (min > obj->square_root_min[start / obj->block_size]){
     min = obj->square_root_min[start / obj->block_size];
   }
   start = start + obj->block_size;
 }

 while (start <= end){
   if (min > obj->arr[start]){
    min = obj->arr[start];
   }
   start++;
 }

 return min;

}

int query_sum(SQUARE_ROOT * obj, int start, int end){

 int sum = 0;
 int min = INT_MIN;

 // first let's sum element before the distink block
 while (start < end && start % obj->block_size  != 0 && start != 0){
   sum = sum + obj->arr[start];
   start++;
 }

 // add sum from distinc blocks
 while (start + obj->block_size - 1 <= end ){
   sum = sum + obj->square_root_sum[start / obj->block_size];
   start = start + obj->block_size;
 }

 // add what's left
 while (start <= end){
   sum = sum + obj->arr[start];
   start++;
 }

 return sum;

}


void main(){
 
  int * arr = (int *)malloc(sizeof(int) * 9);
  arr = (int[9]){1, 5, 2, 4, 6, 1, 3, 5, 7};

  //int arr[] =  {1, 5, 2, 4, 6, 1, 3, 5, 7};
  int size = sizeof(arr)/sizeof(arr[0]);
  static int sqrt = 3;
  int * square_root_sum_arr = (int *)malloc(sizeof(int) * sqrt);
  //int square_root_sum_arr[sqrt];
  int square_root_min_arr[sqrt];
  printArr(arr, size);
  

  SQUARE_ROOT obj = {
    sqrt,
    arr,
    square_root_sum_arr,
    square_root_min_arr
  }; 
  
  preprocess(&obj);
  printArr(obj.square_root_sum, obj.block_size);
  printArr(obj.square_root_min, obj.block_size);
  int start = 1;
  int end = 4;
  int sum = query(&obj, SUM, start, end);
  int min = query(&obj, MIN, start, end);
  printf("Sum of range [%d - %d] is %d\n", start, end, sum);
  printf("Min of range [%d - %d] is %d\n", start, end, min);
   
}
