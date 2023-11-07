#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *prev;
    struct NODE *next;
};
void dllTraversal(struct NODE *head)
{
    struct NODE *p = head;
    struct NODE *q = head;
    printf("Traversal on next dirn.\n");
    while (p != NULL)
    {
        printf("Element %d\n", p->data);
        p = p->next;
        if (q->next != NULL)
        {
            q = q->next;
        }
    }
    printf("Traversal on prev dirn.\n");
    while (q != NULL)
    {
        printf("Element %d\n", q->data);
        q = q->prev;
    }
}
struct NODE *insertAtFirst(struct NODE *head, int value)
{
    struct NODE *ptr = (struct NODE *)malloc(sizeof(struct NODE));
    ptr->data = value;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    return ptr;
}
int main()
{
    // definition and initializaton
    struct NODE *head = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *N2 = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *N3 = (struct NODE *)malloc(sizeof(struct NODE));
    // data assignment
    head->data = 7;
    head->prev = NULL;
    head->next = N2;
    N2->data = 14;
    N2->prev = head;
    N2->next = N3;
    N3->data = 21;
    N3->prev = N2;
    N3->next = NULL;
    // functions
    dllTraversal(head);
    head = insertAtFirst(head, 1);
    dllTraversal(head);
    return 0;
}