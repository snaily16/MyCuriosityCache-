#include<stdio.h>
 
int main()
{
  int arr[3][4] = { 
      {10, 11, 12, 13}, 
      {20, 25, 22, 23}, 
      {30, 31, 32, 33} 
  };
  printf("%d, %d", **arr, *(*(arr+1)+1));
}
