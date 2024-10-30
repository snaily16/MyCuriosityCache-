/*-------------------- bubble_sort.c --------------------*/
#include <stdio.h>
#include <string.h>

#define MAX_BUF 256

long arr[10] = { 3,6,1,2,3,8,4,1,7,2};
char arr2[5][20] = {"Mickey", "Donald","Goofy", "Minnie", "Daisy"};
//void bubble(int *pa, int N);
void bubble(void *pa, int width, int N, int (*fptr)(const void*, const void *));
int compare_long(const void *m, const void *n);
int compare_string(const void *m, const void *n);

int main(void)
{
    int i;
    puts("\nBefore Sorting:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%ld ", arr[i]);
    }
    puts("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s, ", arr2[i]);
    }
    bubble(arr, sizeof(long), 10, compare_long);
    bubble(arr2, 20, 5, compare_string);
    puts("\nAfter sorting:\n");

    for (i = 0; i < 10; i++)
    {
        printf("%ld ", arr[i]);
    }
    puts("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s, ", arr2[i]);
    }
    return 0;
}

//void bubble(void *pa, size_t width, int N)
void bubble(void *pa, int width, int N, int (*fptr)(const void*, const void *))
{
    int i, j, k;
    unsigned char buf[MAX_BUF];
    unsigned char *bp = pa;
    for (i = N-1; i >= 0; i--)
    {
        for (j = 1; j <= i; j++)
        {
            k = fptr((void *)(bp + width*(j-1)), (void *)(bp + j*width));
            if(k > 0)
            {
                memcpy(buf, bp + width*(j-1), width);
                memcpy(bp + width*(j-1), bp+width*j, width);
                memcpy(bp + j*width, buf, width);
            }
        }
    }
}

int compare_long(const void *m, const void *n){
    long *m1, *n1;
    m1 = (long *)m;
    n1 = (long *)n;
    return (*m1 > *n1);
}

int compare_string(const void *m, const void *n){
    char *m1 = (char *) m;
    char *n1 = (char *)n;
    return (strcmp(m1, n1));
}
