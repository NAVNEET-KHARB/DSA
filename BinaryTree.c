// Linked representation of a binary tree
#include <stdio.h>
#include <stdlib.h>
// Structure of an individual Node of the tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Function for creating a Node with a value
struct Node *createNode(int data_value)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data_value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// Function for assigning Children to left and right nodes
struct Node *assignChildren(struct Node *parentNode, struct Node *leftChild, struct Node *rightChild)
{
    parentNode->left = leftChild;
    parentNode->right = rightChild;
    return parentNode;
}
int main()
{
    // Creating nodes using createNode() function
    struct Node *p = createNode(0);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(2);
    // Assigning children to p
    p = assignChildren(p, p1, p2);
    // Checking if the process is successfull
    printf("The left child of p is %d\n", p->left->data);
    printf("The right child of p is %d\n", p->right->data);
    return 0;
}