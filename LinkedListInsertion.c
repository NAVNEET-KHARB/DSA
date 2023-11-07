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
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;
    return head;
}
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    printf("LinkedList before Insertion.\n");
    linkedListTraversal(head);
    // Inserton at beginning
    // head = insertAtFirst(head, 4);
    // Insertion In Between
    // head = insertInBetween(head, 78, 3);
    // Insert At End
    // head = insertAtEnd(head, 45);
    head = insertAfterNode(head, second, 49);
    printf("\nLinkedList after Insertion.\n");
    linkedListTraversal(head);
    return 0;
}