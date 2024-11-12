#include <stdio.h>

#define MAX 5  

struct Queue {
    int items[MAX];
    int front, rear;
};


void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}


int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;  
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to queue\n", value);
}


void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int value = q->items[q->front];
    printf("%d dequeued from queue\n", value);
    q->front++;
    if (q->front > q->rear) {
        // Reset queue if it becomes empty
        q->front = q->rear = -1;
    }
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 40);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    display(&q);

    return 0;
}
