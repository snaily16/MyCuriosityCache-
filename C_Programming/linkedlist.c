#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(0);
    }
    // (*newNode).data = data;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data){
    struct Node* nn = createNode(data);
    if(*head==NULL){
        *head=nn;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL)
        temp=temp->next;
    temp->next = nn;
    nn->next=NULL;
} 

void printList(struct Node* head){
    struct Node* ptr = head;
    while(ptr!=NULL){
        printf("[%d] ->", ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct Node* head = NULL;
    insertNode(&head,10);
    insertNode(&head,20);
    insertNode(&head,30);
    printList(head);

}
