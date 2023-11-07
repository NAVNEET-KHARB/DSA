#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
int isEmpty(struct NODE *f)
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    struct NODE *n = (struct NODE *)malloc(sizeof(struct NODE));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct NODE **f, struct NODE **r, int val)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
    }
    else
    {
        struct NODE *n = (struct NODE *)malloc(sizeof(struct NODE));
        n->data = val;
        n->next = NULL;
        if (isEmpty(*f))
        {
            *f = *r = n;
        }
        else
        {
            (*r)->next = n;
            *r = n;
        }
    }
}
void queueTraversal(struct NODE *f)
{
    if (isEmpty(f))
    {
        printf("Queue Underlow\n");
    }
    else
    {
        struct NODE *p = f;
        while (p != NULL)
        {
            printf("Element : %d\n", p->data);
            p = p->next;
        }
    }
}
int dequeue(struct NODE **f)
{
    if (isEmpty(*f))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    struct NODE *q = *f;
    *f = (*f)->next;
    int val = q->data;
    free(q);
    return val;
}
void search(struct NODE *f, int key)
{
    if (isEmpty(f))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        struct NODE *q = f;
        int pos = 1;
        int flag = 0;
        while (q != NULL)
        {
            if (q->data == key)
            {
                flag = 1;
                break;
            }
            q = q->next;
            pos++;
        }
        if (flag == 1)
        {
            printf("Element %d is found in the queue at position %d\n", key, pos);
        }
        else
        {
            printf("Element %d is not found in the queue\n", key);
        }
    }
}
void queueTop(struct NODE *f, struct NODE *r)
{
    if (isEmpty(f))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The top/rear elenment of the queue is %d\n", r->data);
    }
}
void queueBottom(struct NODE *f)
{
    if (isEmpty(f))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The bottom/front elenment of the queue is %d\n", f->data);
    }
}
int main()
{
    struct NODE *f = NULL;
    struct NODE *r = NULL;
    enqueue(&f, &r, 1);
    enqueue(&f, &r, 11);
    enqueue(&f, &r, 21);
    enqueue(&f, &r, 31);
    search(f, 1);
    int a = dequeue(&f);
    printf("Element %d dequeued from the queue\n", a);
    search(f, 1);
    queueTraversal(f);
    queueTop(f, r);
    queueBottom(f);
    return 0;
}