#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    int data;
} TreeNode;

typedef struct Node
{
    struct Node *link;
    TreeNode *data;

} Node;

void createEmptyQueue(Node **front, Node **rear)
{
    (*front) = NULL;
    (*rear) = NULL;
}

bool isEmpty(Node **front, Node **rear)
{
    return (*front) == NULL && (*rear) == NULL;
}

void enqueue(Node **front, Node **rear, TreeNode *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    if (isEmpty(front, rear) == true)
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->link = newNode;
        (*rear) = newNode;
    }
    return;
}

TreeNode *dequeue(Node **front, Node **rear)
{
    if (isEmpty(front, rear) == true)
    {
        return NULL;
    }
    TreeNode *temp = (*front)->data;
    Node *p = (*front);
    (*front) = (*front)->link;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    free(p);
    return temp;
}

int sizeOfQueue(Node **front)
{
    Node *temp = (*front);
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->link;
    }

    return size;
}

TreeNode *newNode(int data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;

    return node;
}

bool isCompleteTree(TreeNode *root)
{
    Node *front;
    Node *rear;
    bool noChild = false;
    createEmptyQueue(&front, &rear);
    enqueue(&front, &rear, root);
    while (isEmpty(&front, &rear) != true)
    {
        TreeNode *current = dequeue(&front, &rear);
        if (current->left == NULL)
        {
            noChild = true;
        }
        else if (noChild)
        {
            return false;
        }
        else
        {
            enqueue(&front, &rear, current->left);
        }

        if (current->right == NULL)
        {
            noChild = true;
        }
        else if (noChild)
        {
            return false;
        }
        else
        {
            enqueue(&front, &rear, current->right);
        }
    }

    return true;
}

// let min be root
// preorder --> update min
void minNodeInBT(TreeNode *root, TreeNode **min)
{
    if (root == NULL)
    {
        return;
    }
    minNodeInBT(root->left, min);
    minNodeInBT(root->right, min);
    if (root->data < (*min)->data)
    {
        (*min) = root;
    }
}

int main()
{
    // Test case 1
    TreeNode *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    printf("Test case 1: %s\n", isCompleteTree(root1) ? "Yes(Complete)" : "No (Incomplete)");

    TreeNode *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    printf("Test case 2: %s\n", isCompleteTree(root2) ? "Yes(Complete)" : "No (Incomplete)");

    TreeNode *root3 = newNode(1);
    root3->left = newNode(2);
    root3->right = newNode(3);
    root3->left->left = newNode(4);
    printf("Test case 3: %s\n", isCompleteTree(root3) ? "Yes(Complete)" : "No (Incomplete)");

    TreeNode *root4 = newNode(1);
    root4->left = newNode(2);
    root4->right = newNode(3);
    root4->left->left = newNode(4);
    root4->left->right = newNode(5);
    root4->right->left = newNode(6);
    root4->right->right = newNode(7);
    printf("Test case 4: %s\n", isCompleteTree(root4) ? "Yes(Complete)" : "No (Incomplete)");

    TreeNode *root5 = newNode(9);
    root5->left = newNode(2);
    root5->right = newNode(3);
    root5->left->left = newNode(4);
    root5->left->right = newNode(5);
    root5->right->right = newNode(6);
    printf("Test case 5: %s\n", isCompleteTree(root5) ? "Yes(Complete)" : "No (Incomplete)");
    TreeNode *minNode = root5;
    minNodeInBT(root5, &minNode);
    printf("min node %d ", minNode->data);

    return 0;
}