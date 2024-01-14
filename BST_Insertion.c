#include <stdio.h>
#include <stdlib.h>
/*
Algo for Insertion in a BST:->
1 First make sure the no we want to insert isn't present in the BST
2 Then find out the ideal position for insertion in accordance to the rules of the BST
3 Link the nodes
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
void insertBST(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Casn't insert %d because it is already in BST\n", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *newInsert = createNode(key);
    if (key < prev->data)
    {
        prev->left = newInsert;
    }
    else
    {
        prev->right = newInsert;
    }
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
int main()
{
    struct Node *root = createNode(5);
    struct Node *c1 = createNode(3);
    struct Node *c2 = createNode(6);
    struct Node *c3 = createNode(1);
    struct Node *c4 = createNode(4);
    root = assignChildren(root, c1, c2);
    c1 = assignChildren(c1, c3, c4);
    insertBST(root, 2);
    inOrder(root);
    printf("\n%d", root->left->left->right->data);
    return 0;
}