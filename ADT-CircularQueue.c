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
    if ((ptr->rear + 1) % ptr->size == ptr->front)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct QUEUE *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->size;
        ptr->arr[ptr->rear] = val;
    }
}
int dequeue(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    ptr->front = (ptr->front + 1) % ptr->size;
    int val = ptr->arr[ptr->front];
    return val;
}
void cQueueTraversal(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        for (int i = ptr->front + 1; i < ptr->rear + 1; i++)
        {
            printf("Element : %d\n", ptr->arr[i]);
        }
    }
}
void queueTop(struct QUEUE *ptr){
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The top element of Queue is %d\n",ptr->arr[ptr->rear]);
    }
}
void queueBottom(struct QUEUE *ptr){
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The bottom element of Queue is %d\n",ptr->arr[ptr->front+1]);
    }
}
void Peek(struct QUEUE *ptr,int key){
    if (isEmpty(ptr))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        if (key>ptr->front && key<=ptr->rear && key>0)
        {
            
            printf("Element at index %d is %d",ptr->arr[key]);
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
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    // dequeue(q);
    cQueueTraversal(q);
    queueBottom(q);
    queueTop(q);
    return 0;
}