#include <stdio.h>

#define MAX 5

struct stack
{
    int top;
    int arr[MAX];
};

void createStack(struct stack *s){
    s->top = -1;
    printf("Stack initialized with top value at -1\n");
}

int isEmpty(struct stack *s){
    return (s->top == -1);
}

int main() {
    struct stack s;

    createStack(&s);

    if (isEmpty(&s))
    {
        printf("Stack is empty\n");
    }else{
        printf("Stack is not-empty\n");
    }
    
    
    return 0;
}