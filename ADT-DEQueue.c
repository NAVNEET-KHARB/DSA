#include <stdio.h>
#include <stdlib.h>
struct QUEUE
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct QUEUE *ptr)
{
    if (ptr->front == ptr->rear)
    {
        return 1;
    }
    return 0;
}
int isFull(struct QUEUE *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
void enqueueF(struct QUEUE *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (ptr->front == 0)
        {
            printf("No space to assign elements from front\n");
        }
        else
        {
            ptr->arr[ptr->front] = val;
            ptr->front--;
        }
    }
}
void enqueueR(struct QUEUE *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
    }
}
int dequeueF(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        ptr->front++;
        int val = ptr->arr[ptr->front];
        return val;
    }
}
int dequeueR(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->rear];
        ptr->rear--;
        return val;
    }
}
void queueTraversalDE(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        if (ptr->front < 0)
        {
            for (int i = 0; i < ptr->front; i++)
            {
                printf("Element : %d\n", ptr->arr[i]);
            }
        }
        for (int i = ptr->front + 1; i < ptr->rear + 1; i++)
        {
            printf("Element : %d\n", ptr->arr[i]);
        }
    }
}
void peek(struct QUEUE *ptr, int pos)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        if (pos != ptr->front && pos <= ptr->rear && pos >= 0)
        {
            printf("Element at position %d is %d\n", pos, ptr->arr[pos]);
        }
        else
        {
            printf("Invalid Position\n");
        }
    }
}
int main()
{
    struct QUEUE *q = (struct QUEUE *)malloc(sizeof(struct QUEUE));
    q->size = 100;
    q->front = 0;
    q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueueR(q, 1);
    enqueueR(q, 11);
    enqueueR(q, 21);
    enqueueR(q, 13);
    enqueueR(q, 41);
    dequeueF(q);
    enqueueF(q, 12);
    queueTraversalDE(q);
    peek(q,1);
    peek(q,0);
    peek(q,5);
    return 0;
}