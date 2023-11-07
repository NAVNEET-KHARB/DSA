#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void lLTraversal(struct Node *top)
{
    while (top != NULL)
    {
        printf("Element : %d\n", top->data);
        top = top->next;
    }
}
struct Node *push(struct Node *top, int data)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return top;
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = top;
        top = p;
        return top;
    }
}
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        struct Node *p = *top;
        *top = (*top)->next;
        int x = p->data;
        free(p);
        return x;
    }
}
int Peek(struct Node *top, int pos)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else if (pos == 0)
    {
        return -1;
    }
    struct Node *p = top;
    for (int i = 0; (i < pos - 1 && p != NULL); i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}
int stackTop(struct Node *top)
{
    if (isEmpty(top))
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}
int stackBottom(struct Node *top)
{
    struct Node *p = top;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}
int main()
{
    struct Node *top = NULL;
    top = push(top, 1);
    top = push(top, 11);
    top = push(top, 21);
    top = push(top, 31);
    top = push(top, 41);
    int ele = pop(&top);
    // printf("Element %d popped successfully.\n", ele);
    lLTraversal(top);
    // int pos;
    // printf("Enter the pos : ");
    // scanf("%d", &pos);
    // if (Peek(top, pos) == -1)
    // {
    //     printf("Invalid position\n");
    // }
    // else
    // {
    //     int p = Peek(top, pos);
    //     printf("The element at position %d is %d\n", pos, p);
    // }
    // if (stackTop(top) != -1)
    // {
    //     int t = stackTop(top);
    //     printf("Top element of stack is %d\n", t);
    // }
    // else
    // {
    //     printf("Stack Underflow\n");
    // }
    // int b = stackBottom(top);
    // printf("Bottom element of stack is %d\n", b);
    return 0;
}