#include <stdio.h>
#include <stdlib.h>

// Colors to indicate the state of vertices
enum Color
{
    WHITE,
    GRAY,
    BLACK
};

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
    enum Color *color;
    int *discoveryTime;
    int *finishingTime;
    int time;
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
    graph->color = (enum Color *)malloc(numVertices * sizeof(enum Color));
    graph->discoveryTime = (int *)malloc(numVertices * sizeof(int));
    graph->finishingTime = (int *)malloc(numVertices * sizeof(int));
    graph->time = 0;
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->color[i] = WHITE; // Initialize all vertices as not visited (WHITE)
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

// DFS Visit function to recursively explore vertices
void DFSVisit(Graph *graph, int vertex)
{
    graph->color[vertex] = GRAY; // Mark vertex as discovered (GRAY)
    graph->discoveryTime[vertex] = ++(graph->time);
    printf("Vertex %d discovered at time %d\n", vertex, graph->discoveryTime[vertex]);

    Node *temp = graph->adjLists[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (graph->color[adjVertex] == WHITE)
        {
            DFSVisit(graph, adjVertex);
        }
        temp = temp->next;
    }

    graph->color[vertex] = BLACK; // Mark vertex as explored (BLACK)
    graph->finishingTime[vertex] = ++(graph->time);
    printf("Vertex %d explored at time %d\n", vertex, graph->finishingTime[vertex]);
}

// Depth-First Search (DFS) algorithm
void DFS(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->color[i] == WHITE)
        {
            DFSVisit(graph, i);
        }
    }
}

int main()
{
    // Create a graph with 6 vertices
    Graph *graph = createGraph(6);

    // Add some edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // Perform DFS traversal
    DFS(graph);

    return 0;
}
