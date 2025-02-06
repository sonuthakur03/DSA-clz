#include <stdio.h>

#define MAX 5 // maximum size of stack

struct stack
{
    int top;
    int arr[MAX];
};

// Function to create stack
void createStack(struct stack *s){
    s->top = -1;

    // Initialize the array to 1 (or any value to make stack full)
    for (int i = 0; i < MAX ; i++)
    {
        s->arr[++s->top] = 1;
    }

    printf("Stack initialized with top value at -1\n");
}

// Function to check if the stack is full
int isFull(struct stack *s){
    return (s->top == MAX - 1);
}

int main() {
    struct stack s;

    createStack(&s);

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