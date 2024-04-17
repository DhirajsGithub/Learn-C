#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Color codes for vertices
#define WHITE 0
#define GRAY 1
#define BLACK 2

// Queue data structure
typedef struct
{
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Functions for queue operations
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->rear == -1;
}

void enqueue(Queue *queue, int value)
{
    if (queue->rear == MAX_VERTICES - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1)
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(Queue *queue)
{
    int item;
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    return item;
}

// Structure to represent a node in the adjacency list
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// Structure to represent the graph
typedef struct
{
    int numVertices;
    Node **adjLists;
    int *colors;
} Graph;

// Function to create a new node
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (Node **)malloc(numVertices * sizeof(Node *));
    graph->colors = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->colors[i] = WHITE; // Initialize all vertices as undiscovered
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// BFS algorithm
void BFS(Graph *graph, int startVertex)
{
    Queue *queue = createQueue();
    graph->colors[startVertex] = GRAY; // Mark the start vertex as discovered
    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;
            if (graph->colors[adjVertex] == WHITE)
            {
                graph->colors[adjVertex] = GRAY; // Mark the adjacent vertex as discovered
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
        graph->colors[currentVertex] = BLACK; // Mark the current vertex as fully explored
    }

    free(queue);
}

int main()
{
    // Create a graph with 6 vertices
    Graph *graph = createGraph(6);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("BFS Traversal starting from vertex 0: ");
    BFS(graph, 0);

    return 0;
}
