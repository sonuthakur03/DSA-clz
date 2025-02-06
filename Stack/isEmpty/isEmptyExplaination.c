#include <stdio.h>

#define MAX 5

typedef struct stack
{
    int top;
    int arr[MAX];
} st;

// Function to create stack
void createStack(st *s)
{
    s->top = -1;

    // Initialize the array to 0 (or any value that represents "empty")
    for (int i = 0; i < MAX; i++)
    {
        s->arr[i] = 0;
    }

    printf("Stack initialized with top value at -1\n");
}

// Function display stack with either empty or value with index
void displayStack(st *s)
{
    for (int i = MAX - 1; i >= 0; i--)
    {
        if (s->arr[i] == 0)
        {
            printf("Empty at index %d\n", i);
        }
        else
        {
            printf("%d ", s->arr[i]);
        }
    }
}


// Function to show if the stack is empty or not
int isEmpty(st *s)
{
    return (s->top == -1);
}

int main()
{
    st s;

    createStack(&s);
    displayStack(&s);

    if (isEmpty(&s))
    {

        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not-empty\n");
    }

    return 0;
}