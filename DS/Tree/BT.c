#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// function to create a node for the tree
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add a child node to the given parent node
void addChild(Node *parent, Node *child, bool left)
{
    if (parent == NULL)
    {
        parent = child;
        return;
    }
    if (left)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }
}

int heightOfBt(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lef = heightOfBt(root->left);
    int rig = heightOfBt(root->right);

    return fmax(lef, rig) + 1;
}

int numberOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lef = numberOfNodes(root->left);
    int right = numberOfNodes(root->right);
    return lef + right + 1;
}

void displayTree(Node *root, int depth)
{
    if (root == NULL)
        return;

    displayTree(root->right, depth + 1);
    if (depth != 0)
    {
        for (int i = 0; i < depth - 1; i++)
            printf("|\t"); // for indentation
        printf("|---->%d\n", root->data);
    }
    else
    {
        printf("%d\n", root->data);
    }

    displayTree(root->left, depth + 1);
}

// Function to print nodes at the given level

void printGivenLevel(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level);
    }
}

// Function to perform level order traversal
void levelOrder(struct Node *root)
{
    int height = heightOfBt(root);
    for (int i = 0; i <= height; i++)
        printGivenLevel(root, i);
}

void deleteTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // post order
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main()
{

    Node *root = createNode(1);
    Node *two = createNode(2);
    Node *three = createNode(3);
    Node *four = createNode(4);
    Node *five = createNode(5);
    Node *six = createNode(6);

    addChild(root, two, true);
    addChild(root, three, false);
    addChild(three, four, true);
    addChild(three, five, false);
    addChild(four, six, true);

    displayTree(root, 0);
    printf("height of tree %d \n", heightOfBt(root));
    printf("Number of node s %d \n", numberOfNodes(root));

      // Displaying the tree
    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");
    deleteTree(root);
    root = NULL;

    return 0;
}