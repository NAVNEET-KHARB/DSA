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
int match(char a,char b){
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}
int ParanthesisMatch(char * exp){
    struct Stack * s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size =strlen(exp);
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char));
    char popped_ch;
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='('||exp[i]=='['||exp[i]=='{')
        {
            Push(s,exp[i]);
        }
        else if (exp[i]==')'||exp[i]==']'||exp[i]=='}')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            popped_ch = Pop(s);
            if (!match(popped_ch,exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    return 0;
}
int main()
{
    char *exp = "3+2*(5)";
    if (ParanthesisMatch(exp))
    {
        printf("The paranthesis is matched.");
    }
    else
    {
        printf("The paranthesis is not matched.");
    }
    return 0;
}