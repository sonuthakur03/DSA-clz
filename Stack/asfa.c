#include<stdio.h>
#include<stdlib.h>

#define MAX 15 // maximun stack value

// stack structure
struct stack
{
    
    int top;
    int arr[MAX];
};

//function to initialize stack
void createstack(struct stack*s)
{
    s->top=-1;
}
// function to check if the stack is empty
int isEmpty(struct stack*s)
{
    
    return(s->top==-1);
}

// function to checl if the stack is full
int isFull(struct stack*s)
{

    return (s->top==MAX -1);
}

// functin to push an element onto the stack
void push(struct stack *s, int value)
{

    if (isFull(s))
    {
        printf("stack overflow! cannot push %d\n", value);
        return;
    }
    s->arr[++s->top]= value;
    printf("pushed %d onto the stack\n", value);
}

// function to pop an element from the stack
int pop(struct stack *s)
{
    if(isEmpty(s)){
        printf("stack underflow! No element to pop\n");
        return -1;
    }
    return s->arr[s->top--];
}

// function to return the top element
int peek(struct stack *s)
{
   if (isEmpty(s))
   {
    printf("stack is empty!\n");
    return -1;
   }
   return s->arr[s->top];
}

// function to display the stack
void display(struct stack *s)
{
    if (isEmpty(s)){
     printf("stack is empty!\n");
     return;
    }
    printf("srack element:");
    for (int i = s-> top; i >=0; i--)
    {
        printf("%d", s->arr[i]);
    }
    printf("\n");
 }

 // menu code
 int main()
 {
    struct stack s;
    createstack(&s);
    
    push(&s,10);
    push(&s,20);
    push(&s,30);
    display(&s);

    printf("popped:%d\n", pop(&s));
    display(&s);

    printf(" top element:%d\n", peek(&s));
    return 0;
 }