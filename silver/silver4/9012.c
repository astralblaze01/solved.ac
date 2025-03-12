#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    char * strStack;
    char * value;
    int top;
} stack;

void pop(stack *popStack);
void push(stack *pushStack, char bracks);
void printStack(stack *ptStack);


void pop(stack *popStack)
{
    popStack->top--;
}

void push(stack *pushStack, char bracks)
{
    pushStack->top++;
    pushStack->strStack[pushStack->top] = bracks;
}

void printStack(stack *ptStack)
{   
    for(int i = 0; i <= ptStack->top; i++)
        {
            printf("%c ",ptStack->strStack[i]);
        }
    printf("\n");
}

int main()
{
    int n, index = 0;
    
    stack *arr = (stack*)malloc(sizeof(stack));
    arr->strStack = (char*)malloc(sizeof(char));
    arr->value = (char*)malloc(sizeof(char));
    arr->top = -1;
    

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        {
            scanf("%s", arr->value);
            while(1)
                {
                    if(arr->value[index] == '\0')
                    {
                        if(arr->top == -1)
                        {
                            printf("YES\n");
                        }
                        else
                        {
                            printf("NO\n");
                        }
                        index = 0;
                        arr->top = -1;
                        break;
                    }
                    else
                    {

                        push(arr, arr->value[index]);
                        // printStack(arr);
                        if(arr->value[index] == ')' && arr->strStack[arr->top - 1] =='(')
                        {
                            pop(arr);
                            pop(arr);   
                            // printStack(arr);
                        }
                    }
                    index++;
                }
        }
}