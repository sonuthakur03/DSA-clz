#include <stdio.h>

#define MAX 5 // maximum size of stack

struct stack
{
    int top;
    int arr[MAX];
};

void createStack(struct stack *s){
    s->top = -1;
    printf("Stack initialized with top value at -1\n");
}

int main() {
    struct stack s;

    createStack(&s);
    return 0;
}