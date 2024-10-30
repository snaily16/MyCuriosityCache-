#include<stdio.h>

void f1(int *p){
    p=3;
}

void f2(int **p){
    *p=3;
}

void main(){
    int *p=2;
    f1(p);
    printf("%u ", p);
    f2(&p);
    printf("%u ", p);
}
