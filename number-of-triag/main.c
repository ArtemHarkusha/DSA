#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define BUF_SIZE_MAX 1024 * 1024
#define EXIT_ERROR 1
#define EXIT_OK 0

int convertToInt(char *);
unsigned int * getInput(int *);
unsigned int * parseInput(char *, int, int *);
void printArr(int *, int);
int ** findTriag(int *, int, int *);

void printArr(int arr[], int size){

  printf("%d", arr[0]);
  for (unsigned int i = 1; i < size; i++){
    printf(" %d", arr[i]);
  }
  printf("\n");

}

int cmpfunc (const void * a, const void * b) {
   return ( *(unsigned int*)a - *(unsigned int*)b );
}

int ** findTriagSorted(int arr[], int size, int * returnSize){

  qsort(arr, size, sizeof(unsigned int), cmpfunc);
  printArr(arr, size);
   int l = 0;
   int r = l + 1;
   for (int i = size - 1; i >= 2; i--){
       
    while (l < i - 1){
      if (arr[i] < arr[l] + arr[l]) {
   
        while(r < i){
          printf("%u %u %u\n", arr[i], arr[l], arr[l]);
          r++;
        }
      }
      l++;
     }


     }


}


int ** findTriag(int arr[], int size, int * returnSize){

  *returnSize = 0;
  unsigned int insertPos = 0;
  int ** result = (int **)malloc(*returnSize * sizeof(int *));
  if (!result){
    exit(EXIT_ERROR);
  }
  //memset(result, 0b0, *returnSize * sizeof(int *));

  for (int i = 0; i < size - 2; i++){
    for (int j = i + 1; j < size - 1; j++){
      for (int k = j + 1; k < size; k++){
        if (arr[i] < arr[j] + arr[k] && 
            arr[j] < arr[i] + arr[k] && 
            arr[k] < arr[i] + arr[j]){
          
         /* 
          *returnSize = *returnSize + 1;
          result = (int **)realloc(result, *returnSize * sizeof(int *));
          if (!result){
            exit(EXIT_ERROR);
          }
          result[insertPos] = (int *)malloc(3 * sizeof(unsigned int));
          if (!result[insertPos]){
            exit(EXIT_ERROR);
          }
          result[insertPos][0] = arr[i];
          result[insertPos][1] = arr[j];
          result[insertPos][2] = arr[k];
           
          insertPos++;
          */
             
        }
      }
    }

  }

  return result; 

}

int convertToInt(char * input){

  int result = 0;
  for (int i = 0; input[i] >= '0' && input[i] <= '9'; i++){
    result =  10 * result  + (input[i] - '0');
  }

  return result; 

}

unsigned int * parseInput(char input[],int size, int *returnSize){

  unsigned int * buff = (unsigned int *)malloc(BUF_SIZE * sizeof(unsigned int));
  if (!buff){
    exit(EXIT_ERROR);
  }
  unsigned int buf_size = BUF_SIZE;
  unsigned int i = 0;
  
  for (unsigned j = 0; j < size; j++){

   if (input[j] >= '0' && input[j] <= '9'){
     if (i > buf_size){
       buf_size = buf_size + BUF_SIZE;
       buff = (int *)realloc(buff, buf_size);
       if (!buff){
         exit(EXIT_ERROR);
       }
     }
     buff[i] = convertToInt(input + j * sizeof(char));
     while (input[j] >= '0' && input[j] <= '9'){
       j++;
     }
     j--;
     i++;    
   }
  }
   
   free(input);
   *returnSize = i; 
   return buff;
  
}

unsigned int * getInput(int *returnSize){
  
   char * buff = (char *)malloc(BUF_SIZE * sizeof(char));
   if (!buff){
     exit(EXIT_ERROR);
   }
   int c = getchar();
   unsigned int buf_size = BUF_SIZE;
   unsigned int i = 0;
   while (c != EOF && c != '\n'){
   
    if (i > buf_size){
      buf_size = buf_size + BUF_SIZE;
      if (buf_size > BUF_SIZE_MAX){
        printf("\nToo long input size. Must be less than %d chars long.\n", BUF_SIZE_MAX);
        exit(EXIT_ERROR);
      }
      buff = (char *)realloc(buff, buf_size * sizeof(char));
      if (!buff){
        exit(EXIT_ERROR);
      }
    }
    buff[i] = c;
    c = getchar();
    i++;
       
   }

  return parseInput(buff, i, returnSize);

} 


int main(){
   
  int inputSize;
  unsigned int * input =  getInput(&inputSize);
  // unsigned int arr[] = {4, 6, 3, 7};

  int returnSize = 0;
   
  //printArr(input, inputSize);
  //int ** result = findTriag(input, inputSize, &returnSize);
  int ** result = findTriagSorted(input, inputSize, &returnSize);
  
  for (unsigned int i = 0; i < returnSize  ; i++){
    printArr(result[i], 3);
    free(result[i]);
  }
  
  free(input);
  //free(result);

  exit(EXIT_OK);

}
