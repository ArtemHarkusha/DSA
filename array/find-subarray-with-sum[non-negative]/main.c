#include <stdio.h>
#include "helpers.h"

// a struct containing start and end position of subarray inside a given array
typedef struct SubArrayPos {
  int start;
  int end;
} SUB_ARR_POS;

SUB_ARR_POS findSubarrayWithSum(int arr[], int size, int sum){
 
  SUB_ARR_POS p = { 0, -1 };
  int tmp = arr[0];
  
  // iterate thtough array summing members
  //    * exit if the sum equels the searched value
  //    * if sum is bigger than the searched value, increment starting index and remove it's value from sum.
  for (unsigned int i = 1; i < size; i++){
     
     p.end = i;
     tmp = tmp + arr[i];
     
     if (tmp < sum){
       continue;
     }
     // start position can't be greater or equal to the end position
     while (tmp > sum && p.start < p.end - 1){
       tmp = tmp - arr[p.start];
       p.start++;
     }

     if (tmp == sum){
       break;
     }
  }
  
  // subarray was not found
  if (tmp != sum){
    p.start = -1;
    p.end = -1;
  }

  return p; 

}

void main(){

  int arr[] = {1, 0, -7, -3, 10, 5};
  int sum = 0;

  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);

  // let's find subarray indices
  SUB_ARR_POS p = findSubarrayWithSum(arr, size, sum);

  if (p.start != -1 || p.end != -1){
    printf("Sub-array found.\n\tstarting index:%d\n\tending index:%d\n", p.start, p.end);
    // size a new array
    int subArraySize = p.end - p.start + 1;
    int subArray[subArraySize];

    //fill-out the new arr
    for (unsigned int i = p.start; i <= p.end; i++){
      subArray[i - p.start] = arr[i];
    }

    printArr(subArray, subArraySize);
  } else {
    printf("Sub-array not found.\n");
  }


}
