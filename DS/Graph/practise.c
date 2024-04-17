#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

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

typedef struct Graph
{
    Node **adjLists;
    enum Color *colors;
    int numOfVertices;
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

Graph *createGraph(int numOfVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->adjLists = (Node **)malloc(sizeof(Node *) * numOfVertices);
    graph->numOfVertices = numOfVertices;
    graph->colors = (enum Color *)malloc(sizeof(enum Color) * numOfVertices);
    graph->discoveryTime = (int *)malloc(sizeof(int) * numOfVertices);
    graph->finishingTime = (int *)malloc(sizeof(int) * numOfVertices);
    graph->time = 0;

    for (int i = 0; i < numOfVertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->colors[i] = WHITE;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int des)
{
    Node *newNode = createNode(des);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFSVisit(Graph *graph, int startVer)
{
    graph->colors[startVer] = GRAY;
    graph->discoveryTime[startVer] = ++(graph->time);
    printf("Vertex %d discovered at time %d\n", startVer, graph->discoveryTime[startVer]);
    Node *temp = graph->adjLists[startVer];
    while (temp != NULL)
    {
        int cureVer = temp->vertex;
        if (graph->colors[cureVer] == WHITE)
        {
            DFSVisit(graph, cureVer);
        }
        temp = temp->next;
    }
    graph->colors[startVer] = BLACK;
    graph->finishingTime[startVer] = ++(graph->time);
    printf("Vertex %d explored at time %d\n", startVer, graph->finishingTime[startVer]);
}

void DFS(Graph *graph)
{
    for (int i = 0; i < graph->numOfVertices; i++)
    {
        if (graph->colors[i] == WHITE)
        {
            DFSVisit(graph, i);
        }
    }
}

int main()
{
    // Create a graph with 6 vertices
    Graph *graph = createGraph(6);
    printf("%d ", graph->numOfVertices);
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
