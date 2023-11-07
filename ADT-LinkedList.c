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
    linkedListTraversal(head);
    return 0;
}