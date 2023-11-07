#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char Pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void Push(struct Stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        // printf("Value %d pushed successfully.\n", val);
    }
}
int stackTop(struct Stack *ptr)
{
    return ptr->arr[ptr->top];
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}
int Precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}
char *InfixToPostfix(char *infix)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = strlen(infix);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *Postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Infix Traversal Tracker
    int j = 0; // Postfix Addition Tracker
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            Postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (Precedence(infix[i]) > Precedence(stackTop(s)))
            {
                Push(s, infix[i]);
                i++;
            }
            else
            {
                Postfix[j] = Pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        Postfix[j] = Pop(s);
        j++;
    }
    Postfix[j] = '\0';
    return Postfix;
}
int main()
{
    char *Infix = "3+2/3*56-7";
    printf("The Postfix expression of %s is %s", Infix, InfixToPostfix(Infix));
    return 0;
}
