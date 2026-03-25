#include "file_operation.h"
#include <stdio.h>

int file_read(char *file_name){
    FILE *file;
    file = fopen(file_name, "r");
    
    fclose(file);
    return 0;
}
