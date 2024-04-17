#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
// Structure for a node in adjacency list
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;
// Structure for adjacency list
typedef struct
{
    Node *head;
} AdjList;
// Structure for the graph
typedef struct
{
    int numVertices;
    AdjList *array;
} Graph;

Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->array = (AdjList *)malloc(sizeof(AdjList) * numVertices);
    for (int i = 0; i < numVertices; i++)
    {

        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void displayGraph(Graph *graph)
{
    printf("Adjacency List Representation:\n");
    for (int i = 0; i < graph->numVertices; ++i)
    {
        printf("Vertex %d: ", i);
        Node *temp = graph->array[i].head;
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
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    // Create a graph with the given number of vertices
    Graph *graph = createGraph(numVertices);
    printf("Enter the adjacency matrix:\n");
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
            if (adjacencyMatrix[i][j] == 1)
            {
                addEdge(graph, i, j);
            }
        }
    }
    // Display the adjacency list of the graph
    displayGraph(graph);
    return 0;
}