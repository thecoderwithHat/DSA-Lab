#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    if(newNode == NULL){
        printf("Unable to allocate");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main(){
    
}