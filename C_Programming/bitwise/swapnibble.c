#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    int num = atoi(argv[1]);
    int nibble = (num<<4 & 0xF0) | (num>>4 & 0x0F);
    printf("%d\n", nibble);
    return 0;
}
