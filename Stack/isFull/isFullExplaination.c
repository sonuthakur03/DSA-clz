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

    // Initialize the array to 1 (or any value to make stack full)
    for (int i = 0; i < MAX ; i++)
    {
        s->arr[++s->top] = 1;
    }

    printf("Stack initialized with top value at -1\n");
}

// Function display stack with either empty or value with index
void displayStack(st *s)
{
    printf("Stack: \n");
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

// Function to check if the stack is full
int isFull(st *s){
    return (s->top == MAX - 1);
}

int main() {
    st s;

    createStack(&s);
    displayStack(&s);

    if (isFull(&s))
    {
        printf("Oh no!! Stack overflow, Stack is full\n");
    }
    else
    {
        printf("Stack is not full");
    }
    
    return 0;
}