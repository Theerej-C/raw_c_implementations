#include <stdio.h>

int main(){
    FILE* file;
    // char arr[100] = "This is my text to be return \n and this is next line";
    char data[10];
    file = fopen("test.txt", "r");
    if(!file){
        printf("File Not Found");
    }
    else{
        printf("File opened successfully");
        // fputs(arr, file);
        // fputs("\n",file);
        while(fgets(data, 10, file)!=NULL){
            printf("%s",data);
        }
    }
    fclose(file);
    return 0;

}
