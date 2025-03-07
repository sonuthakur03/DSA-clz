#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10  // Define maximum queue size

// Structure for Priority Queue
struct PriorityQueue {
    int items[MAXQUEUE];
    int size;
};

typedef struct PriorityQueue pq;

// Function to check if the queue is empty
int IsEmpty(pq *q) {
    return (q->size == 0);
}

// Function to check if the queue is full
int IsFull(pq *q) {
    return (q->size == MAXQUEUE);
}

// Function to insert an element into the priority queue (Ascending Order)
void Enqueue(pq *q, int newitem) {
    if (IsFull(q)) {
        printf("Queue is full\n");
        return;
    }

    int i;
    for (i = q->size - 1; i >= 0 && q->items[i] > newitem; i--) {
        q->items[i + 1] = q->items[i];  // Shift elements
    }
    q->items[i + 1] = newitem;  // Insert at the correct position
    q->size++;
    printf("Inserted: %d\n", newitem);
}

// Function to remove the highest priority element (smallest element)
int Dequeue(pq *q) {
    if (IsEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return q->items[--q->size];  // Remove the smallest element
}

// Function to display the queue elements
void Display(pq *q) {
    if (IsEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue (Ascending Order): ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function to test the priority queue
int main() {
    pq q;
    q.size = 0;

    Enqueue(&q, 30);
    Enqueue(&q, 10);
    Enqueue(&q, 50);
    Enqueue(&q, 20);
    Enqueue(&q, 40);

    Display(&q);

    printf("Dequeued: %d\n", Dequeue(&q));
    printf("Dequeued: %d\n", Dequeue(&q));

    Display(&q);

    return 0;
}