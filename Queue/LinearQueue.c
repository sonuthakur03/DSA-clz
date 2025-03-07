#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 5  // Define maximum queue size

// Structure for Queue
struct queue {
    int front;
    int rear;
    int items[MAXQUEUE];
};

typedef struct queue qt;

// Function to check if the queue is empty
int IsEmpty(qt *q) {
    if (q->rear < q->front)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int IsFull(qt *q) {
    if (q->rear == MAXQUEUE - 1)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue (Enqueue)
void Enqueue(qt *q, int newitem) {
    if (IsFull(q)) {
        printf("Queue is full\n");
        exit(1);
    } else {
        q->rear++;
        q->items[q->rear] = newitem;
    }
}

// Function to remove an element from the queue (Dequeue)
int Dequeue(qt *q) {
    if (IsEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    } else {
        return q->items[q->front++];
    }
}

// Main function to test the queue
int main() {
    qt q;
    q.front = 0;
    q.rear = -1;

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);

    printf("Dequeued item: %d\n", Dequeue(&q));
    printf("Dequeued item: %d\n", Dequeue(&q));

    return 0;
}