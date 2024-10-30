#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct {
    struct Node* head;
} MyLinkedList;

struct Node* createNode(int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    obj->head=NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    struct Node* curr = obj->head;
    int i=0;
    while(i<index && curr!=NULL){
        curr = curr->next;
        i++;
    }
    if(curr==NULL) return -1;
    return curr->data;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct Node* curr = obj->head;
    struct Node* temp = createNode(val);
    if(curr==NULL) {
        obj->head = temp;
    }
    else{
        temp->next = curr;
        obj->head = temp;
    }
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct Node* curr = obj->head;
    struct Node* temp = createNode(val);
    if(curr==NULL){
        obj->head = temp;
    }
    else{
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct Node* curr = obj->head;
    struct Node* temp = createNode(val);
    if(index==0){
        myLinkedListAddAtHead(obj, val);
    }
    else{    
        if(curr!=NULL){
        for(int i=0; i<index-1; i++){
            if(curr->next != NULL)
                curr = curr->next;
            else 
                return;
        }
        temp->next = curr->next;
        curr->next = temp;
        }
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    struct Node* curr = obj->head;
    struct Node* prev = NULL;
    if(curr==NULL) return;
    if(index==0){
        obj->head = curr->next;
        free(curr);
    }
    else{    
        if(curr!=NULL)
        for(int i=0; i<index; i++){
            if(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            else 
                break;
        }
        if(curr==NULL) return;
        prev->next = curr->next;
        free(curr);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    struct Node* curr = obj->head;
    struct Node* deleted = NULL;
    //if(curr==NULL) free(obj);
    while(curr!=NULL){
        deleted = curr;
        curr=curr->next;
        free(deleted);
    }
    free(obj);
}

void myLinkedListPrint(MyLinkedList* obj){
    struct Node* curr = obj->head;
    printf("\n");
    if(curr==NULL)
        printf("List is empty.\n");

    while(curr){
        printf(" (%d) --> ", curr->data);
        curr = curr->next;
    }
}

int main()
{
    MyLinkedList *obj = myLinkedListCreate();
    myLinkedListAddAtIndex(obj, 1, 0);
    myLinkedListPrint(obj);
    int g = myLinkedListGet(obj,0);
    printf("\nGet at 0: %d\n", g);
    myLinkedListFree(obj);
}
