# Problem

Write a program to print all the LEADERS in the array. An element is a leader if it is greater than all the elements to its right side. And the rightmost element is always a leader.

For example:

Input: arr[] = {16, 17, 4, 3, 5, 2},
Output: 17, 5, 2

Input: arr[] = {1, 2, 3, 4, 5, 2},
Output: 5, 2

[Leaders in an array](https://www.geeksforgeeks.org/leaders-in-an-array/)

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
