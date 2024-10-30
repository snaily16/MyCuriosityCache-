// Taks 1.2 -  Define a doubly linked list of heap-allocated strings in C. 
// Write functions to insert, find, and delete items from it. Test them
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char val;
    struct node* next;
    struct node* prev;
} node;

node* initialize_node(char c){
    node* nn =  malloc(sizeof(node));
    nn->val = c;
    nn->prev = NULL;
    nn->next = NULL;
    return nn;
}

int list_len(node *head){
    node * temp = head;
    int len=0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

// Add char to doubly linked list to form string
node* add_element(node *head, int k, char c){
    node* new_node = initialize_node(c);
    if(head==NULL){
        head = new_node;
        return head;
    }
    node* temp = head;
    int ctr=0;
    while(temp->next!=NULL && ctr<k){
        ctr++;
        temp = temp->next;
    }

    if(temp==head && k<=ctr){ //add at front of head
        new_node->prev = NULL;
        head = new_node;
    }
    else if(temp->next == NULL && k>ctr){ // add at back
        temp->next = new_node;
        new_node->prev = temp;
        return head;
    }
    else{   // add at k position
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
    }
    temp->prev = new_node;
    new_node->next = temp;
    return head;
}

// Remove element from string
node * remove_element(node* head, int k){
    if(head==NULL) return NULL;
    node* temp = head;
    int ctr=0;
    if(k<0) return head;
    while(temp->next!=NULL && ctr<k){
        ctr++;
        temp = temp->next;
    }
    //remove head
    if(temp==head){
        head->next->prev = NULL;
        head = head->next;
    }
    else{
    temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

int find_element(node *head, char c){
    if(head == NULL) return -1;
    int ctr=0;
    node* current = head;
    while(current != NULL){
        if(current->val == c){
            //printf("Element present at index %d", ctr);
            return ctr;
        }
        current = current->next;
        ctr++;
    }
    return -1;
}

node* add_string(node *head, int k, char str[]){
    int i=0;
    //k += list_len(head); 
    while(str[i]!='\0'){
        head = add_element(head,i+k,str[i]);
        i++;
    }
    return head;
}

node* remove_char(node *head, char ch){
    int k = find_element(head, ch);
    head = remove_element(head,k);
    return head;
}

node* remove_all_char(node *head, char ch){
    int k;
    do{
        k = find_element(head, ch);
        head = remove_element(head,k);
    }while(k!=-1);
    return head;
}

void free_list(node *head){
    node * temp = head;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void print_string(node *head){
    node * temp = head;
    printf("\nString: ");
    while(temp != NULL){
        printf("%c", temp->val);
        temp = temp->next;
    }
}

node* create_string(char str[]){
    node * head = NULL;
    head = add_string(head, 0, str);
    return head;
}

node* append_string(node* original, char str[], int k){
    original = add_string(original, k, ".konnichiwa.");
    return original;
}

void main(){
    node* s = create_string("helloworld!");
    print_string(s);
    s = append_string(s, "konnichiwa", 10);
    print_string(s);
    printf("\nchar 'k' is present at index %d \n", find_element(s,'k'));
    printf("\nString length: %d", list_len(s));
    printf("\nRemove first occurrence of char 'o': ");
    s=remove_char(s, 'o');
    print_string(s);
    printf("\nRemove all occurrence of char 'w': ");
    s=remove_all_char(s, 'w');
    print_string(s);
    free_list(s);
}
