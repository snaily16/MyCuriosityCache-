#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    int num = atoi(argv[1]);
    int n=num;
    int ans=0;
    while(n){
        ans += n&1;
        n=n>>1;
    }
    printf("%d\n", ans);

    // method 2
    n=num; 
    int count=0;
    while(n){
        n = n & (n-1);
        count++;
    }
    printf("%d\n", count);
    return 0;
}
