/*-------------------- bubble_sort.c --------------------*/

#include <stdio.h>

int arr[10] = { 3,6,1,2,3,8,4,1,7,2};

void bubble(int *pa, int N);
int compare(void *m, void *n);

int main(void)
{
    int i;
    putchar('\n');
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    bubble(arr,10);
    putchar('\n');

    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void bubble(int *pa, int N)
{
    int i, j, t;
    for (i = N-1; i >= 0; i--)
    {
        for (j = 1; j <= i; j++)
        {
            //if (compare(a[j-1],a[j]))
            if (compare(&pa[j-1],&pa[j]))
            {
                t = pa[j-1];
                pa[j-1] = pa[j];
                pa[j] = t;
            }
        }
    }
}

int compare(void *m, void *n){
    int *m1, *n1;
    m1 = (int *)m;
    n1 = (int *)m;
    return (*m1>*n1);
}
