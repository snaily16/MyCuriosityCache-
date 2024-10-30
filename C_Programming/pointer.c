#include<stdio.h>

struct n{
    int a;
    float b;
    char c;
}
int main(){
    int a=2;
    int *p=&a;
    int v = malloc(10);
    int *p = &v;
    free(v);
    int a[7] ={1,2,3,4,5,3,4};
    for(int i=0; i<n; i++){
        //base = a[i];
        for(int j=i+1; j<n; j++){
            if(a[j]==a[i]){
                printf("%d is duplicate\n", a[i]);
                break;
            }
        }
    }
    printf("%d", *p);

    // Remove nth node 
    // 1 <-> 2 <-> 3 <-> 4 <-> 1
    struct node* temp = head;
    struct node* p = NULL;

    int i=0;
    while(i<n && temp!=NULL){
        p = temp;
        temp = temp->next;
        i++;
    }
    // 1 <-- --> 2 <-- --> 3
    // p         t
    p->next = temp->next;
    temp->next->prev = p
    free(temp);

    int arr[7]={1,3,6,5,7,2};
    int sum1=0, sum2=0;
    // sum of 1 to n
    for(int i=1; i<=n; i++){
        sum1 = sum1 + i;
        sum2 = sum2 + arr[i-1];
    }
    int diff = sum1 - sum2;
    
    char *s = "some sentence";
    int arr[26];
    for(int i=0; i<strlen(s); i++){
        arr[s[i] - 'a'] = 1;
    }
    for(int i=0; i<26; i++){
        if(arr[i]==0)
    }

    0xabcdefgh
        00 01 02 04
        gh ef cd ab

        ab cd ef gh

    int num;
    // 8 8 8 8
    num = ((num & 0xff000000) >> 24 | (num & 0xff) <<24 | (num & 0xff0000) >> 8 | (num & 0xff00) << 8);

    // singly linked list delete nth node from last
    // len -n 
    // temp -> 1 -> 2 ->3 -> 4 -> 5 // 2nd last node
    //              t2

    temp = NULL;
    temp->next = head;
    t2 = temp;
    prev = NULL:
    for(int i=0; i<n; i++){
        t2 = t2->next;
    }
    while(t2!=NULL){
        prev = temp;
        temp = temp->next;
        t2 = t2->next;
    }
    prev->next = temp->next;
    free(temp);
}
