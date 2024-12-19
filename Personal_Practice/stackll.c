#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;                
    struct StackNode* next;  
};

void push(struct StackNode** top, int value) {
struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = *top;

    *top = newNode;
}
void pop(struct StackNode** top){
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
}

void disp(struct StackNode* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct StackNode* temp = top; // Temporary pointer for traversal
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data); // Print the data of the current node
        temp = temp->next;         // Move to the next node
    }
    printf("\n");
}


int main(){
    struct StackeNode* top = NULL;

    push(&top, 10);
    push(&top,50);
    disp(&top);
    pop(&top);
    disp(top);

}
  
