#include <stdio.h>
#include <stdlib.h>
/*
Binary Search Tree -> It is a type of binary tree data structure with the following properties:-
1 The left subtree of a node contains only nodes with keys lesser than the node’s key.
2 The right subtree of a node contains only nodes with keys greater than the node’s key.
3 The left and right subtree each must also be a binary search tree.
4 There are no duplicate nodes.
Visual Representation of a Binary Search Tree
                   9
                  /  \
                 4    11
                / \     \
               2   7     15
                   /\    /
                  5  8  14
**Imp property -> In-order traversal of a BST gives us an ascending sorted array.
2->4->5->7->8->9->11->14->15
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
// In-order Traversal
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// Function to check if a Binary Tree is BST or not?
int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        // Check if the left subtree isBST
        if (!isBST(root->left))
        {
            return 0;
        }
        // Check if there exists a previous of the root ie a child of the root. If yes, then root's data value must be greater than the prev's data value
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        // Now, do it for right subtree
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main()
{
    // Node Creation
    struct Node *root = createNode(5);
    struct Node *c1 = createNode(3);
    struct Node *c2 = createNode(6);
    struct Node *c3 = createNode(1);
    struct Node *c4 = createNode(4);
    // Node linking
    root = assignChildren(root, c1, c2);
    c1 = assignChildren(c1, c3, c4);
    // In-order Traversal
    inOrder(root);
    // Checking whether the tree is BST or not?
    printf("\n%d", isBST(root));
    return 0;
}