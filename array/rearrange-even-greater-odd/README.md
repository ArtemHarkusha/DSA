# Problem

Given an array A of n elements, sort the array according to the following relations :  

A[i] >= A[i-1]                    , if i is even,  ∀ 1 <= i <= n
A[i] <= A[i-1]                    , if i is odd ,  ∀ 1 <= i <= n
Print the resultant array.

Examples :  

Input : A[] = {1, 2, 2, 1}
Output :  1 2 1 2
Explanation : 
For 1st element, 1  1, i = 2 is even.
3rd element, 1  1, i = 4 is even.

Input : A[] = {1, 3, 2}
Output : 1 3 2
Explanation : 
Here, the array is also sorted as per the conditions. 
1  1 and 2 < 3.

[Rearrange array such that even positioned are greater than odd](https://www.geeksforgeeks.org/rearrange-array-such-that-even-positioned-are-greater-than-odd/)

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

# Notes

It's not very clear from the description if the first element has index 0 or 1. 
Implementation assumes that we start from zero. 
Also, it's not tested properly, so it may not produce the correct result for some inputs.
