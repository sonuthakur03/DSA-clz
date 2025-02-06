#include <stdio.h>

#define MAX 5 // maximum size of stack

typedef struct stack
{
    int top;
    int arr[MAX];
} st;

// Function to create stack
void createStack(st *s){
    s->top = -1;

    // Initialize the array to 0 (or any value that represents "empty")
    for (int i = 0; i < MAX; i++)
    {
        s->arr[i] = 0;
    }
    printf("Stack initialized with top value at -1\n");
}

// Function to check if the stack is full
int isFull(st *s){
    return (s->top == MAX - 1);
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
            printf("%d at index %d\n", s->arr[i],i);
        }
    }
}

// Function to push elements into stack
void push(st *s, int value){
    if (isFull(s))
    {
        printf("Oh no!! Stack overflow, Stack is full\n");
        return;
    }
    s->arr[++s->top] = value;
    printf("\nPushed %d into stack\n\n",value);
}

int main() {
    st s;

    createStack(&s);

    push(&s,20);

    displayStack(&s);

    push(&s,30);
    displayStack(&s);

    return 0;
}