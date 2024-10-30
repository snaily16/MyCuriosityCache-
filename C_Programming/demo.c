#include<stdio.h>

const int a=96;
extern int b[10];
int main(){
    b[1]=2;
    printf("%d \n", b[1]);
    int * p = (int *)&a;
    //*p = *p+1;
    *p = 1;
    printf("%p, %d", p, *p);
}
