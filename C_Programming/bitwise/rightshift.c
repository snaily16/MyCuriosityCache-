#include<stdio.h>

int main(int argc, char** argv){
    int n=16;
    for(int i=0; i<n; i++){
        printf("%d: %d\n",i, i>>1);
    }
}
