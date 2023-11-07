#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *arr;
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
void Pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("%d Popped successfully\n", val);
    }
}
int Peek(struct Stack *ptr, int i)
{
    int arrInd = ptr->top - i + 1;
    if (arrInd < 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrInd];
    }
}
void Push(struct Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow.");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("Value %d pushed successfully.\n", val);
    }
}
void display(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        for (int i = 0; i <= ptr->top; i++)
        {
            printf("%d\n", ptr->arr[i]);
        }
    }
}
void stackTop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Top element of the stack is %d\n", ptr->arr[ptr->top]);
    }
}
void stackBottom(struct Stack *ptr)
{
    printf("Bottom element of the stack is %d\n", ptr->arr[0]);
}
int sortsearch(struct Stack *ptr, int key)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int high = ptr->top;
        int low = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (ptr->arr[mid] == key)
            {
                return mid;
            }
            else if (ptr->arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        printf("The element %d isn't found in the stack.", key);
        return -1;
    }
}
int search(struct Stack *ptr, int key)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        for (int i = 0; i <= ptr->top; i++)
        {
            if (ptr->arr[i] == key)
            {
                return i;
            }
        }
        printf("The element %d isn't found in the stack.", key);
        return -1;
    }
}
int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // s->arr[0]=5;
    // s->top++;
    // if(isEmpty(s)){
    //     printf("Stack is Empty");
    // }
    // else{
    //     printf("Stack isn't empty.");
    // }
    Push(s, 43);
    Push(s, 44);
    Push(s, 45);
    Push(s, 46);
    Push(s, 47);
    Push(s, 48);
    Push(s, 49);
    Push(s, 50);
    Push(s, 2);
    Push(s, 51);
    Pop(s);
    // for (int j = 1; j <= s->top + 1; j++)
    // {
    //     printf("Element at %d is %d\n", j, Peek(s, j));
    // }
    // int pos;
    // printf("Enter the position : ");
    // scanf("%d", &pos);
    // if (Peek(s, pos) != -1)
    // {
    //     printf("The no. at pos %d is %d", pos, Peek(s, pos));
    // }
    // display(s);
    // stackTop(s);
    // stackBottom(s);
    int key;
    printf("Enter the value you want to search for : ");
    scanf("%d", &key);
    if (search(s, key) != -1)
    {
        printf("The element %d is found at index %d\n", key, search(s, key));
    }
    // if (sortsearch(s, key) != -1)
    // {
    //     printf("The element %d is found at index %d\n", key, sortsearch(s, key));
    // }

    return 0;
}