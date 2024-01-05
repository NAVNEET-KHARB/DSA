#include <stdio.h>
#include <stdlib.h>
/*
Traversal - Visiting each location/address of the data structure atleast once
Types of traversal in Binary Tree-
1 PreOrder Traversal - Root->Left SubTrree->Right SubTree
2 PostOrder Traversal - Left SubTrree->Right SubTree->Root
3 InOrder Traversal - Left SubTrree->Root->Right SubTree
*/
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
// PreOrder Traversal Function(Root->Left SubTrree->Right SubTree)
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
// PostOrder Traversal Function(Left SubTrree->Right SubTree->Root)
void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
// InOrder Traversal Function(Left SubTrree->Root->Right SubTree)
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int main()
{
    // Node creation and linking
    struct Node *root = createNode(4);
    struct Node *c1 = createNode(1);
    struct Node *c2 = createNode(6);
    struct Node *c3 = createNode(5);
    struct Node *c4 = createNode(2);
    /*
    Visual Representation of tree
                   4
                  /  \
                 1    6
                / \
               5   2
    */
    root = assignChildren(root, c1, c2);
    c1 = assignChildren(c1, c3, c4);
    // Traversals
    printf("PreOrder Traversal\n");
    preOrder(root);
    printf("\nPostOrder Traversal\n");
    postOrder(root);
    printf("\nInOrder Traversal\n");
    inOrder(root);
    return 0;
}