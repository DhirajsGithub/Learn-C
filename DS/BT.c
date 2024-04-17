#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new binary tree node
TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
TreeNode *insert(TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform a pre-order traversal of the binary tree
void preOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform a post-order traversal of the binary tree
void postOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to free the memory used by the binary tree
void freeTree(TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    TreeNode *root = NULL;

    // Insert values into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Perform pre-order traversal
    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    // Perform post-order traversal
    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    // Free the memory used by the binary tree
    freeTree(root);

    return 0;
}
