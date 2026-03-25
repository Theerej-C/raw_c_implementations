#ifndef ARRAY_H
#define ARRAY_H
typedef struct array Array;
Array *init_array();
int expand_array(Array *arr);
void destroy_array(Array *arr);
int add(Array *arr, int a);
int rm(Array *arr, int position);
int array_size(Array *arr);
void print_array(Array *arr);
#endif
