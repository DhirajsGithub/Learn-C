#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to a directed graph
void addEdge(Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
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
            printf("%d -> ", temp->vertex);
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
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}
