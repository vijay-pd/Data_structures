#include <stdio.h>
#include <stdlib.h>

struct ArrayStack {
        int top;
        int capacity;
        int *array;
};

struct ArrayStack *CreateStack() 
{
        struct ArrayStack *S = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
        if(!S)
            return NULL;
        S->capacity = 6;
        S->top = -1;
        S->array = (int *)malloc(S->capacity * sizeof(int));
        if(!S->array)
            return NULL;
        return S;
}

int IsEmptyStack(struct ArrayStack *S)
{ 
       return (S->top == -1); // If the condition is true one is returned else 0 is returned
}
 
int IsFullStack(struct ArrayStack *S)
{
        return (S->top == S->capacity - 1);
}

void Push(struct ArrayStack *S, int data)
{
        if(IsFullStack(S))
            printf("Stack Overflow\n");
        else 
            S->array[++S->top] = data;
}

int Pop(struct ArrayStack *S)
{
        if(IsEmptyStack(S))
        {
            printf("Stack Underflow\n");
            return 0;
        }        
        else
            return S->array[S->top--];
} 

void DeleteStack(struct ArrayStack *S)
{
        if(S) {
            if(S->array)
                free(S->array);
            free(S);
        }
}


int main(int argc, char *argv[])
{
    int value=0;
    struct ArrayStack *S;
    S = CreateStack();
    Push(S, 22);
    printf("Top:%d\n", S->top);
    Push(S, 33);
    printf("Top:%d\n", S->top);
    Push(S, 44);
    printf("Top:%d\n", S->top);
    Push(S, 55);
    printf("Top:%d\n", S->top);
    Push(S, 66);
    printf("Top:%d\n", S->top);
    Push(S, 77);
    printf("Top:%d\n", S->top);
    
    value = Pop(S);
    printf("Value:%d Top:%d\n",value, S->top);
    value = Pop(S);
    printf("Value:%d Top:%d\n",value, S->top);
    value = Pop(S);
    printf("Value:%d Top:%d\n",value, S->top);
    value = Pop(S);
    printf("Value:%d Top:%d\n",value, S->top);
    value = Pop(S);
    printf("Value:%d Top:%d\n",value, S->top);
    value = Pop(S);
    printf("Value:%d Top:%d\n",value, S->top);
    
    DeleteStack(S);
    return 0;

}

