#include<stdio.h>
#include<stdlib.h>

int main(){

int *a = malloc(8);
printf(" a (size 8): %p\n", a);
free(a);
printf("free a\n");

int *b = malloc(8);
printf(" b (size 8): %p\n", b);

int *c = malloc(8);
printf(" c (size 8): %p\n", c);

free(b);
printf("free b\n");

int *d = malloc(16);
printf(" d (size 16): %p\n", d);
int *e = malloc(2);
printf(" e (size 2): %p\n", e);
free(d);
printf("free d\n");
free(c);
free(e);
printf("free c\n");
printf("free e\n");
}
