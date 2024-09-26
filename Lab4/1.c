#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int data1;
    struct node *next;
};
struct node* add_begin(struct node* head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = NULL;

    ptr->next = head;
    head = ptr;
    return head;
};
struct node* add_end(struct node* head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;       
    ptr->next = NULL;    

    if (head == NULL) {
        return ptr;
    }   
     struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    
    temp->next = ptr;

    return head; 
}
struct node* add_inbtw(struct node*head, int d, int pos){
    struct node * ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = NULL;

    if (head == NULL)
    {
        return ptr;
    }
   struct node* temp = head;
   
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        ptr->next = temp->next;  
        temp->next = ptr;        
    }
    return head;
    
}

int main(){
    struct node *head= malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 14;
    ptr->next = NULL;

    head->next = ptr;
    int data = 3;

    head = add_begin(head,data);
    head = add_end(head,20);
    head = add_inbtw(head, 19,2);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    return 0 ;
    
  
    
}
