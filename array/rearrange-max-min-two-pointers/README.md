# Problem

Given a sorted array of positive integers, rearrange the array alternately i.e first element should be a maximum value, at second position minimum value, at third position second max, at fourth position second min, and so on.

Examples:

Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
Output: arr[] = {7, 1, 6, 2, 5, 3, 4}

Input: arr[] = {1, 2, 3, 4, 5, 6}
Output: arr[] = {6, 1, 5, 2, 4, 3}

[Rearrange an array in maximum minimum form using Two Pointer Technique](https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/)

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
