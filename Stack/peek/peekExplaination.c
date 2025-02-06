#include <stdio.h>

#define MAX 5

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
        s->arr[++s->top] = (i+1)*10;
    }
    printf("Stack initialized with top value at -1\n");
}

// Function to check if the stack is empty
int isEmpty(st *s){
    return (s->top == -1);
}

// Function to peek the value from stack
int peek(st *s){
    if (isEmpty(s))
    {
        printf("Come on!! Stack underflow, Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function display stack with either empty or value with index
void displayStack(st *s)
{
    printf("\nStack: \n");
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

int main() {
    st s;

    createStack(&s);
    displayStack(&s);

    printf("\nValue peeked at top: %d\n",peek(&s));    
    
    return 0;
}