#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <string.h>

struct array {
  int size;
  int current_size;
  int *pointer;
};
Array * init_array(){
    Array *arr = malloc(sizeof(Array));
    if(!arr){
        return NULL;
    }
    int* ptr =  malloc(5*sizeof(int));
    if(ptr==NULL){
        free(arr);
        return NULL;
    }
    arr->pointer = ptr;
    arr->current_size = 0;
    arr->size = 5;
    return arr;
}
int expand_array(Array *arr){
   int* temp = realloc(arr->pointer, sizeof(int)*arr->size*2); 
    if(temp==NULL){
        return 0;
    }
   arr->pointer = temp;
   arr->size = arr->size*2;
   return 1;
}
void destroy_array(Array *arr){
    arr->pointer = NULL;
    arr->current_size = 0;
    arr->size = 0;
    free(arr->pointer);
    free(arr);
    return;
}
int add(Array *arr,int a){
    if(!arr) return 0;
    if(arr->size==arr->current_size){
        if(!expand_array(arr)){
           return 0; 
        }
    }
    arr->pointer[arr->current_size] = a;
    arr->current_size++;
    return 1;
}

int rm(Array *arr,int position){
    if(!arr) return 0;
    if(position<0||position>arr->current_size){
        return 0;
    }
    memmove(arr->pointer+position ,arr->pointer+position+1,(arr->current_size-position-1)*sizeof(int));
    arr->current_size--;
    return 1;
}

int array_size(Array *arr){
    return arr->current_size;
}

void print_array(Array *arr){
    printf("Printing the array elements: \n");
    for(int i=0;i<arr->current_size;i++){
        printf("%d \n",arr->pointer[i]);
    }
}
