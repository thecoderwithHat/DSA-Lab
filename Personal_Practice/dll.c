#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next=NULL;
    newNode->prev = NULL;

    return newNode;
}
void insertatBegin(struct Node** head, int value){
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    if (*head!=NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
    
    
}
void insertatEnd(struct Node** head, int value){
    struct Node* newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    
    
}
void insertatPos(struct Node** head, int value, int position){
    struct Node* newNode = createNode(value);
    if (position = 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
   for (int i = 1; i < position-1; i++)
    {
       if (temp == NULL)
       {
        printf("Out of bounds");
        free(newNode);
        return;
       }
       temp = temp->next;
       
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode; // Update the prev pointer of the next node
    }
    temp->next = newNode; // Point temp->next to the new node
    newNode->prev = temp;
    
}
void disp(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


int main(){
    struct Node* head = NULL;
    insertatBegin(&head, 10);
    insertatBegin(&head, 87);
    insertatEnd(&head,20);
    insertatPos(&head,17,2);
    disp(head);
}