#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum stack size

// Stack operation code 
typedef struct {
    int top;
    int arr[MAX];
}stack;

stack s;

//Function to initialize stack
void createStack() {
    s.top = -1;
}

// Function to check if the stack is empty
int isEmpty() {
    return (s.top == -1);
}

// Function to check if the stack is full
int isFull() {
    return (s.top == MAX - 1);
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s.arr[++s.top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
 int pop() {
    if (isEmpty(s)) {
        printf("Stack Underflow! No elements to pop\n");
        return -1;
    }
    return s.arr[s.top--];
}

// Function to return the top element
int peek() {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s.arr[s.top];
}

// Function to show the stack
void show() {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}

// Menu code
int main() {
    createStack(s);

    push(10);
    push(30);
    push(50);    
    
	show(s);
    printf("Popped: %d\n", pop(s));
    show(s);

    printf("Top element: %d\n", peek(s));

    return 0;
}