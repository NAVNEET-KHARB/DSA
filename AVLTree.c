#include <stdio.h>
#include <stdlib.h>
/*
AVL Tree -> It stands for Adelson-Velsky-Landis Tree.
An AVL tree defined as a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees for any node cannot be more than one.
The difference between the heights of the left subtree and the right subtree for any node is known as the balance factor of the node.
The AVL tree is named after its inventors, Georgy Adelson-Velsky and Evgenii Landis, who published it in their 1962 paper “An algorithm for the organization of information”.

Applications of AVL Tree:
1 It is used to index huge records in a database and also to efficiently search in that.
2 For all types of in-memory collections, including sets and dictionaries, AVL Trees are used.
3 Database applications, where insertions and deletions are less common but frequent data lookups are necessary
4 Software that needs optimized search.
5 It is applied in corporate areas and storyline games.

Advantages of AVL Tree:
1 AVL trees can self-balance themselves.
2 It is surely not skewed.
3 It provides faster lookups than Red-Black Trees
4 Better searching time complexity compared to other trees like binary tree.
5 Height cannot exceed log(N), where, N is the total number of nodes in the tree.

Disadvantages of AVL Tree:
1 It is difficult to implement.
2 It has high constant factors for some of the operations.
3 Less used compared to Red-Black trees.
4 Due to its rather strict balance, AVL trees provide complicated insertion and removal operations as more rotations are performed.
5 Take more processing for balancing.

Visual Representation of an AVL Tree ->
                            12
                           /  \
                          8   18
                         / \   /
                        5  11 17
                       /
                      4
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
// In Order Traversal
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
    // Creation of Nodes for an AVL Tree
    struct Node *root = createNode(12);
    struct Node *c1 = createNode(8);
    struct Node *c2 = createNode(18);
    struct Node *c3 = createNode(5);
    struct Node *c4 = createNode(11);
    struct Node *c5 = createNode(17);
    struct Node *c6 = createNode(4);
    // Linking the nodes
    root = assignChildren(root, c1, c2);
    c1 = assignChildren(c1, c3, c4);
    c2 = assignChildren(c2, c5, NULL);
    c3 = assignChildren(c3, c6, NULL);
    // Printing the tree
    inOrder(root);
    return 0;
}