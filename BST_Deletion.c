#include <stdio.h>
#include <stdlib.h>
/*
Deletion in BST :-
Case 1 -> Node is a leaf node.
S1) Search for the node.
S2) Delete the node.
Case 2 -> Node isn't a leaf node (immediate child is a leaf node)
S1) Search for the req. node.
S2) Search for it's Inorder Pre & Inorder Post value.
S3) Replace it with either of them and delete the node.
Case 3 -> Node is a root node or is a node whose immediate child isn't a leaf node
S1) Search for the req. node.
S2) Search for it's Inorder Pre & Inorder Post value.
S3) Keep doing this until there's no empty nodes left.
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
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// Function for finding inOrder Predecessor of a node
struct Node *iPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
// Function for deleting a node from the BST
struct Node *deletionBST(struct Node *root, int value)
{
    struct Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    else if (value < root->data)
    {
        root->left = deletionBST(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletionBST(root->right, value);
    }
    else
    {
        iPre = iPredecessor(root);
        root->data = iPre->data;
        root->left = deletionBST(root->left, iPre->data);
    }
    return root;
}
int main()
{
    // Node creation
    struct Node *root = createNode(9);
    struct Node *c1 = createNode(4);
    struct Node *c2 = createNode(11);
    struct Node *c3 = createNode(2);
    struct Node *c4 = createNode(7);
    struct Node *c5 = createNode(15);
    struct Node *c6 = createNode(5);
    struct Node *c7 = createNode(8);
    struct Node *c8 = createNode(14);
    // Node linking
    root = assignChildren(root, c1, c2);
    c1 = assignChildren(c1, c3, c4);
    c2 = assignChildren(c2, NULL, c5);
    c4 = assignChildren(c4, c6, c7);
    c5 = assignChildren(c5, c8, NULL);
    int del;
    printf("Enter the no. you want to delete : ");
    scanf("%d", &del);
    inOrder(root);
    deletionBST(root, del);
    printf("\n");
    inOrder(root);
    return 0;
}