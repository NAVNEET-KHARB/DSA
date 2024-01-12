#include <stdio.h>
#include <stdlib.h>
/*
Application of BST is that it is mainly used for searching
Searching in BST -> It is same as the searching in binary search for array.
TC -> O(logn)
Algo:->
1 Check if the root is NULL.
2 Check if root->data is equal to the searched value.
3 If the searched value is smaller than root->data then search in left ST recursively.
4 If the searched value is greater than root->data then search in right ST recursively.
5 If we are at a leaf node and the value isn't found then return NULL.
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
// Recursive search function for a BST
struct Node *searchRBST(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        searchRBST(root->left, key);
    }
    return searchRBST(root->right, key);
}
// Iterative search function for BST
struct Node *searchIBST(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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
    // Searching for a Node in BST
    int key;
    printf("Enter the value you want to search for in the tree : ");
    scanf("%d", &key);
    // struct Node *n = searchRBST(root, key); // Recursive Search
    struct Node *n = searchIBST(root, key); // Iterative Search
    if (n != NULL)
    {
        printf("Found : %d\n", n->data);
    }
    else
    {
        printf("Element not found.\n");
    }
    return 0;
}