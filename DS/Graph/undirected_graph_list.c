#include <stdio.h>
#include <stdlib.h>

// Define a typedef for the struct Node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Define a typedef for the struct Graph
typedef struct Graph
{
    int numVertices;
    Node **adjLists;
} Graph;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (Node **)malloc(numVertices * sizeof(Node *));
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (since it's an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        Node *temp = graph->adjLists[v];
        printf("Adjacency list of vertex %d\n", v);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    // Create a graph with 5 vertices
    Graph *graph = createGraph(5);

    // Add some edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}
