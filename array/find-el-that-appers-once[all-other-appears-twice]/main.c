#include <stdio.h>
#include "helpers.h"

// so we can use an exclusive OR (XOR) operator on all members
// so that the members that appear twice will turn to 0
// and then we will have only bits left by the unique member. 
int findUniqueMember(int arr[], int size){

  int xor_sum = arr[0];
  
  for (int i = 1; i < size; i++){
    xor_sum = xor_sum ^ arr[i];
  }

  return xor_sum; 
}

void main(){

  int arr[] = {2, 3, 5, 4, 5, 3, 4};
  int size = sizeof(arr)/sizeof(int);

  printArr(arr, size);
  printf("The element that appears only once is: %d\n", findUniqueMember(arr, size));

}
