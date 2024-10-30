#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv){
    const int a = 5;
    //a = 4;
    int *p = &a;
    *p = 4;
    printf("%d\n",a);
    // gcc with -O3 doesn't change a, but without changes it's value
    return EXIT_SUCCESS;
}
