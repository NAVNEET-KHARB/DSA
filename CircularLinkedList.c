#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void circularLLTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct Node *insertAtFirstCLL(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    fifth->next = head;
    printf("Circular Linked List before insertion\n");
    circularLLTraversal(head);
    head = insertAtFirstCLL(head, 49);
    printf("Circular Linked List after insertion\n");
    circularLLTraversal(head);
    return 0;
}