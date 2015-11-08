#include <stdio.h>
#include <stdlib.h>

void writeToFile(char *p){
    
    if(!p)
        printf("\nNothing to write");

    FILE* fp = NULL;
    fp = fopen("dummy.txt", "w");
    
    if(!fp)
        printf("\n File Error!");

    while(*p){
        fwrite(p, sizeof(char), 1, fp); 
        p++;
    }
    // write the null terminating character
    fwrite(p, sizeof(char), 1, fp);
    fclose(fp);
}

void readFromFile(){

    FILE* fp = NULL;
    fp = fopen("dummy.txt", "r");

     if(!fp)
        printf("\n File Error!");

    // capacity 100 bytes
    char* p = (char*)malloc(sizeof(char)*100); 
    char* temp = p;

    while(fread(temp, sizeof(char), 1, fp))
            temp++;

    printf("%s\n", p);
}

int main(){
    char str[] = "Hello";
    //writeToFile(str);
    readFromFile();
    return 0;
}
