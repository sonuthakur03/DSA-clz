// Circular queue without pointer
#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 5

struct queue
{
    int front;
    int rear;
    int items[MAXQUEUE];
};

typedef struct queue qt;

int IsEmpty(qt q)
{
    return (q.front == -1);
}

int IsFull(qt q)
{
    return ((q.rear + 1) % MAXQUEUE == q.front);
}

qt Enqueue(qt q, int newitem)
{
    if (IsFull(q))
    {
        printf("Queue is full\n");
        return q;
    }

    if (IsEmpty(q))
    {
        q.front = 0;
        q.rear = 0;
    }
    else
    {
        q.rear = (q.rear + 1) % MAXQUEUE;
    }

    q.items[q.rear] = newitem;
    printf("Inserted: %d\n", newitem);
    return q; // Return the updated queue
}

qt Dequeue(qt q)
{
    if (IsEmpty(q))
    {
        printf("Queue is empty\n");
        exit(1);
    }

    int data = q.items[q.front];
    printf("Dequeued: %d\n", data);

    if (q.front == q.rear)
    {
        q.front = -1;
        q.rear = -1;
    }
    else
    {
        q.front = (q.front + 1) % MAXQUEUE;
    }

    return q; // Return the updated queue
}

void Display(qt q)
{
    if (IsEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q.front;
    while (1)
    {
        printf("%d ", q.items[i]);
        if (i == q.rear)
            break;
        i = (i + 1) % MAXQUEUE;
    }
    printf("\n");
}

int main()
{
    qt q;
    q.front = -1;
    q.rear = -1;

    q = Enqueue(q, 10);
    q = Enqueue(q, 20);
    q = Enqueue(q, 30);
    q = Enqueue(q, 40);
    q = Enqueue(q, 50);

    Display(q);

    q = Dequeue(q);
    q = Dequeue(q);

    Display(q);

    q = Enqueue(q, 60);
    q = Enqueue(q, 70);

    Display(q);

    return 0;
}
