#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the tree
struct TreeNode
{
    int key;
    struct TreeNode *parent;
    struct TreeNode *leftmostChild;
    struct TreeNode *sibling;
};

// Function to create a node for the tree
struct TreeNode *createNode(int key, struct TreeNode *parent)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->parent = parent;
    newNode->leftmostChild = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Function to add a child node to the given parent node
void addChild(struct TreeNode *parent, struct TreeNode *child)
{
    child->parent = parent;
    if (parent->leftmostChild == NULL)
        parent->leftmostChild = child;
    else
    {
        struct TreeNode *temp = parent->leftmostChild;
        while (temp->sibling != NULL)
            temp = temp->sibling;
        temp->sibling = child;
    }
}

// Function to display the tree (depth-first traversal)
void displayTree(struct TreeNode *root, int depth)
{
    if (root == NULL)
        return;
    for (int i = 0; i < depth; i++)
        printf("| "); // for indentation
    printf("%d\n", root->key);
    displayTree(root->leftmostChild, depth + 1);
    displayTree(root->sibling, depth);
}

// Function to delete the tree
void deleteTree(struct TreeNode *root)
{
    if (root == NULL)
        return;
    deleteTree(root->leftmostChild);
    deleteTree(root->sibling);
    free(root);
}

int main()
{
    // Creating a sample tree
    struct TreeNode *root = createNode(1, NULL);
    struct TreeNode *child2 = createNode(2, root);
    struct TreeNode *child3 = createNode(3, root);
    struct TreeNode *child4 = createNode(4, child2);
    struct TreeNode *child5 = createNode(5, child2);
    struct TreeNode *child6 = createNode(6, child3);

    addChild(root, child2);
    addChild(root, child3);
    addChild(child2, child4);
    addChild(child2, child5);
    addChild(child3, child6);

    // Displaying the tree
    printf("Tree (Depth-First Traversal):\n");
    displayTree(root, 0);

    // Deleting the tree
    deleteTree(root);
    root = NULL;

    return 0;
}
