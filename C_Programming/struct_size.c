#include<stdio.h>
#include<stdlib.h>

struct Demo{
    int a;
    int *p;
    int c;
    int d;
    float b;
};

int main(){
    struct Demo *d = malloc(sizeof(struct Demo));
    struct Demo *ptr = d;
    printf("%ld\n",(char*)(ptr+1)-(char*)ptr);
    d->a=10;
    d->p = malloc(sizeof(int));
    *(d->p) = 20;
    int a;
    int *b=&a ;
    
    printf("%d, %d\n", d->a, *(d->p));
    printf("%lu %lu %lu \n", sizeof(struct Demo), sizeof(a), sizeof(*b));
    return 0;
}
