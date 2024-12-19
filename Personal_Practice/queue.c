#include<stdio.h>
#define MAX 10

struct Queue
{
    int data[MAX];
    int front; 
    int rear;
};

void initQueue(struct Queue* q){
    q->front  = -1 ;
    q->rear = -1;

}
void isEmpty(struct Queue* q){
    return(q->front == -1);
}
void isFull(struct Queue* q){
    return(q->rear == MAX-1);
}

void enqueue(struct Queue* q, int value){
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("enqueue %d \n",value);
    
}
void dequeue(struct Queue* q ){
    int value = q->data[q->front];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;

    }else{
        q->front++;
    }
    printf("Dequed %d \n",value);
    return value;
    

} 

