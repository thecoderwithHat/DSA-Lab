#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} ;
void dispList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
}

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertatBegin(struct Node** head , int value){
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;

}
void insertatEnd(struct Node** head, int value ){
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
    
    
}
void insetatN(struct Node** head, int value, int position){
    struct Node* newNode = createNode(value);

    if (position == 1)
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
    newNode->next = temp-> next;
    temp->next = newNode;
    
    
}
    void deletemidNode(struct Node** head){
        if (*head == NULL || (*head)->next == NULL)
        {
            return ;
        }
        struct Node* slow = *head;// one step at a time
        struct Node* fast = *head;// two steps at a time
        fast = (*head)->next->next;
        while (fast!=NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return ;
    
}

void deleteNode(struct Node** head , int value ){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp !=NULL && temp->data == value)
    {
       *head = temp->next;
       free(temp);
       return;
    }
    while (temp!=NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
    
    

}


int main(){
    struct Node* head = NULL;
    insertatBegin(&head,10);
    insertatBegin(&head,15);
    insetatN(&head,20,2);
    dispList(head);
    deletemidNode(&head);
    dispList(head);

}