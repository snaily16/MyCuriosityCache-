#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
    FILE *readFile = fopen(argv[1], "r");
    FILE *writeFile = fopen(argv[2], "w");

    if(readFile == NULL || writeFile == NULL){
        printf("One file is missing\n");
        return -1;
    }

    char c;
    while((c=fgetc(readFile)) != EOF){
        if(c=='.') c='!';

        fputc(c, writeFile);
    }
    fclose(readFile);
    fclose(writeFile);

}
