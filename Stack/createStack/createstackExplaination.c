#include <stdio.h>

#define MAX 10 // Maximum stack value

typedef struct stack
{
    int top;
    int arr[MAX];
} st;


// Function to create stack
void stackCreation(st *s)
{
    s->top = -1;

    // Initialize the array to 0 (or any value that represents "empty")
    for (int i = 0; i < MAX; i++)
    {
        s->arr[i] = 0;
    }

    printf("Intialized Stack with -1 as top value\n");
}

// Function display stack with either empty or value with index
void displayStack(st *s)
{
    for (int i = MAX - 1; i >= 0; i--)
    {
        if (s->arr[i] == 0)
        {
            printf("Empty at index %d\n",i);
        }
        else
        {
            printf("%d ", s->arr[i]);
        }
    }
}

int main()
{
    st s;

    stackCreation(&s);

    displayStack(&s);

    return 0;
}