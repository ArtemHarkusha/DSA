# Problem

[https://www.geeksforgeeks.org/square-root-sqrt-decomposition-algorithm/](https://www.geeksforgeeks.org/square-root-sqrt-decomposition-algorithm/)

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
