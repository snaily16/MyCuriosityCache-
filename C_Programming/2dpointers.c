#include<stdio.h>
#include<stdlib.h>

void fun(int *p1){
    printf("Inside fun: %d\n", *(p1+2));
}

//void fun2d(int p1[][4]){
void fun2d(int (*p1)[4]){
    printf("Inside fun2d: %d\n", *(*(p1+2)));
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%d, ", *(*(p1+i)+j));
            //printf("%d, ", p1[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char **argv){
    int A[4][4];
    int B[4] = {1,2,3,4};
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            A[i][j]=i;
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%d, ", A[i][j]);
        }
        printf("\n");
    }
    fun(B);
    fun2d(A);
}
