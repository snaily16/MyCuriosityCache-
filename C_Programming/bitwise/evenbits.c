#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int ans = (int) (n & 0xaaaaaaaa);
    printf("%d", ans);
    return 0;
}
