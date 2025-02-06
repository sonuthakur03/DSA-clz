#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum stack size
 
// Struct Structure
struct stack
{
    int top;
    int arr[MAX];
};

// Function to initalize stack
void createStack(struct stack *s){
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct stack *s){
    return (s->top == -1);
}

// Function to check if the stack is full
int isFull(struct stack *s){
    return (s->top == MAX -1);
}

// Function to push am element onto the stack
void push(struct stack *s, int value){
    if (isFull(s))
    {
        printf("Stack Overflow! Cannot push %d\n");
        return;
    }
    s->arr[++s->top] == value;
    printf("Pushed %d onto the stack\n",value);
}

// Function to pop an element from the stack
int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow! No elements to pop\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Function to return the top element 
int peek(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function to display the stack 
void display(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack Elements: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

// Menu code
int main(){
    struct stack *s;
    createStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Popped: %d\n",pop(&s));
    display(&s);

    printf("Top Element: %d\n",peek(&s));

    return 0;
}