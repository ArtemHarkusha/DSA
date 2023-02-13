# Problem

[Move all zeroes to end of array](https://www.geeksforgeeks.org/move-zeroes-end-array/)

# Build 

1. Build helpers 
```sh
pushd ../helpers/
gcc -o helpers.o -c helpers.c
popd
```

2. Build


```sh
# using GeekForGeeks implementation
gcc -I../helpers/  ../helpers/helpers.o main.c

# using own implementation
gcc -DUSE_OWN_IMPLEMENTATION -I../helpers/ ../helpers/helpers.o main.c
```
