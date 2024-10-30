#include<stdio.h>
#include<stdint.h>

int main(){
    uint8_t a[20];
    for(uint8_t i=0; i<20; i++)
        a[i] = i;
    uint32_t *p = (uint32_t*) &a;
    printf("%p, %p, %d, %d \n", &a, p, *p, *(p+1));
    return 0;
}
