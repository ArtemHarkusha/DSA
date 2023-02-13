# Problem

An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively. A number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear at the end of the array.
For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]
[Rearrange positive and negative numbers in O(n) time and O(1) extra space](https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/)

# Build 

1. Build helpers 
```sh
pushd ../helpers/
gcc -o helpers.o -c helpers.c
popd
```

2. Build
```sh
gcc -I../helpers ../helpers/helpers.o main.c
```
