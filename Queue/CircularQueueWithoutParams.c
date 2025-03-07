// Circular queue without parameters
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

qt q;


int IsEmpty()
{
    return (q.front == -1);
}

int IsFull()
{
    return ((q.rear + 1) % MAXQUEUE == q.front);
}

qt Enqueue(int newitem)
{
    if (IsFull())
    {
        printf("Queue is full\n");
        return q;
    }

    if (IsEmpty())
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

qt Dequeue()
{
    if (IsEmpty())
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

void Display()
{
    if (IsEmpty())
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
    q.front = -1;
    q.rear = -1;

    q = Enqueue(10);
    q = Enqueue(20);
    q = Enqueue(30);
    q = Enqueue(40);
    q = Enqueue(50);

    Display(q);

    q = Dequeue(q);
    q = Dequeue(q);

    Display(q);

    q = Enqueue(60);
    q = Enqueue(70);

    Display(q);

    return 0;
}
