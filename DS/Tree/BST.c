#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Definition for a binary tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
TreeNode *insert(TreeNode *root, int data)
{
    // If the tree is empty, create a new node and return it as the root
    if (root == NULL)
    {
        return createNode(data);
    }

    // Otherwise, recursively insert the new node in the appropriate subtree
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    // Return the root of the modified tree
    return root;
}

// Function to print the inorder traversal of the BST
void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

bool isBST(TreeNode *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

// Function to search for a value in the BST
TreeNode *search(TreeNode *root, int key)
{
    // If the tree is empty or the key is found at the root, return the root
    if (root == NULL || root->data == key)
    {
        return root;
    }

    // If the key is smaller than the root's data, search in the left subtree
    if (key < root->data)
    {
        return search(root->left, key);
    }

    // If the key is larger than the root's data, search in the right subtree
    return search(root->right, key);
}

TreeNode *findMinNode(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Function to find the node with given value in BST
TreeNode *findNode(TreeNode *root, int val)
{
    if (root == NULL || root->data == val)
        return root;

    if (val < root->data)
        return findNode(root->left, val);
    else
        return findNode(root->right, val);
}

// Function to find successor of a node in BST
TreeNode *findSuccessor(TreeNode *root, int val)
{
    TreeNode *node = findNode(root, val);
    if (node == NULL)
        return NULL;

    // If the right subtree is not NULL
    if (node->right != NULL)
        return findMinNode(node->right);

    // Traverse up the tree to find the successor
    TreeNode *successor = NULL;
    TreeNode *ancestor = root;
    while (ancestor != node)
    {
        if (node->data < ancestor->data)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
        {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *current = node;
    // Find the leftmost leaf node
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    // Base case: If the tree is empty
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // If key is the same as root's key, then this is the node to be deleted
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    // Create an empty BST
    TreeNode *root = NULL;

    // Insert elements into the BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    printf("isBST %s \n", isBST(root, INT_MIN, INT_MAX) ? "YES" : "NO");

    // Print the inorder traversal of the BST
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
