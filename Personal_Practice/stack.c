#include<stdio.h>
#define MAX 10

struct Stack
{
    int arr[MAX];
    int top;
};

void initStack(struct Stack* stack){
    stack->top = -1;
}
int isFull(struct Stack* stack){
    return stack->top == MAX-1;
}
int isEmpty(struct Stack* stack){
    return stack->top == -1;
}
void push(struct Stack* stack, int value){
    if (isFull(stack))
    {
        printf("Overflow");
    }
    stack->top++;
    stack->arr[stack->top] = value;
    
}
void pop(struct Stack* stack){
    if (isEmpty(stack))
    {
        printf("Stack Underflow");
    }
    int popVal = stack->arr[stack->top];
    stack->top--;
    printf("Popedval %d\n",popVal);
    return popVal;
    
}
void disp(struct Stack* stack){
    for (int i = stack->top; i >=0 ; i--)
    {
        printf("%d ",stack->arr[i]);
    }
    printf("\n");
    
}
int main(){
    struct Stack stack;
    initStack(&stack);
    push(&stack,10);
    push(&stack,17);
    pop(&stack);
    disp(&stack);
}
