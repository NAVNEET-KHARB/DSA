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
void enqueue(struct QUEUE *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue overflow.\n");
    }
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
    }
}
int dequeue(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    ptr->front++;
    int val = ptr->arr[ptr->front];
    return val;
}
void queueTraversal(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        for (int i = ptr->front + 1; i < ptr->rear + 1; i++)
        {
            printf("Element : %d\n", ptr->arr[i]);
        }
    }
}
void search(struct QUEUE *ptr, int key)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        int flag = 0;
        for (int i = ptr->front + 1; i < ptr->rear + 1; i++)
        {
            if (ptr->arr[i] == key)
            {
                flag = 1;
                printf("Element %d found at index %d\n", key, i);
            }
        }
        if (flag == 0)
        {
            printf("Element %d not found in the Queue.\n", key);
        }
    }
}
int searchB(struct QUEUE *ptr, int key)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow.\n");
        return -1;
    }
    else
    {
        int low = ptr->front + 1;
        int high = ptr->rear;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
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
        return -1;
    }
}
void peek(struct QUEUE *ptr, int index)
{
    if (ptr->front + 1 <= index && index <= ptr->rear)
    {
        printf("The element at index %d is %d\n", index, ptr->arr[index]);
    }
    else
    {
        printf("Invalid index\n");
    }
}
void queueTop(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        printf("Top element of queue is %d\n", ptr->arr[ptr->rear]);
    }
}
void queueBottom(struct QUEUE *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        printf("Bottom element of queue is %d\n", ptr->arr[ptr->front + 1]);
    }
}
int main()
{
    //  Queue declaration and initialization
    struct QUEUE *q = (struct QUEUE *)malloc(sizeof(struct QUEUE));
    q->size = 100;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    // Operations
    enqueue(q, 3);
    enqueue(q, 13);
    enqueue(q, 23);
    enqueue(q, 33);
    enqueue(q, 43);
    // dequeue(q);
    queueTraversal(q);
    // search(q, 23);
    int ele;
    printf("Enter the element you want to search for : ");
    scanf("%d", &ele);
    int s = searchB(q, ele);
    if (s != -1)
    {
        printf("The element %d is found at index %d\n", ele, s);
    }
    else
    {
        printf("The element %d isn't found in the queue\n", ele);
    }

    peek(q, 3);
    queueTop(q);
    queueBottom(q);
    // int a = dequeue(q);
    // printf("%d\n", a);
    // if (isEmpty(q))
    // {
    //     printf("Queue Empty");
    // }
    // else
    // {
    //     printf("Queue is not Empty");
    // }
    return 0;
}