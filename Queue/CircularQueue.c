// Circular Queue
#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 5  

struct queue {
    int front;
    int rear;
    int items[MAXQUEUE];
};

typedef struct queue qt;

int IsEmpty(qt *q) {
    return (q->front == -1);
}

int IsFull(qt *q) {
    return ((q->rear + 1) % MAXQUEUE == q->front);
}

void Enqueue(qt *q, int newitem) {
    if (IsFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (IsEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAXQUEUE;
    }

    q->items[q->rear] = newitem;
    printf("Inserted: %d\n", newitem);
}

int Dequeue(qt *q) {
    if (IsEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }

    int data = q->items[q->front];

    if (q->front == q->rear) { 
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAXQUEUE;
    }

    return data;
}

void Display(qt *q) {
    if (IsEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAXQUEUE;
    }
    printf("\n");
}

int main() {
    qt q;
    q.front = -1;
    q.rear = -1;

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);

    Display(&q);

    printf("Dequeued: %d\n", Dequeue(&q));
    printf("Dequeued: %d\n", Dequeue(&q));

    Display(&q);

    Enqueue(&q, 60);
    Enqueue(&q, 70);

    Display(&q);

    return 0;
}