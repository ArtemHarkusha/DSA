# Problem

Given an array arr[] of non-negative integers and an integer sum, find a subarray that adds to a given sum.

Note: There may be more than one subarray with sum as the given sum, print first such subarray.

Examples:

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Output: Sum found between indexes 2 and 4
Explanation: Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33

[https://www.geeksforgeeks.org/find-subarray-with-given-sum/](https://www.geeksforgeeks.org/find-subarray-with-given-sum/)

# Build 

1. Build helpers 
```sh
pushd ../helpers/
gcc -o helpers.o -c helpers.c
popd
```

2. Build
```sh
gcc -I../helpers/  ../helpers/helpers.o main.c
```
