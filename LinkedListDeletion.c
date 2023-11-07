#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}
struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    // Linked List element declaration
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    // Heap Memory Allocation
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    // Data assignment
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 19;
    third->next = fourth;
    fourth->data = 31;
    fourth->next = fifth;
    fifth->data = 47;
    fifth->next = NULL;
    // Traversal
    printf("Linked List before deletion\n");
    linkedListTraversal(head);
    // head = deleteFirst(head);
    // head = deleteAtIndex(head, 3);
    // head = deleteLast(head);
    head = deleteAtValue(head, 11);
    printf("Linked List after deletion\n");
    linkedListTraversal(head);
    return 0;
}