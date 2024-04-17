#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Define the Graph structure
typedef struct
{
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to initialize the graph
void initializeGraph(Graph *graph, int vertices)
{
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->matrix[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices
void addEdge(Graph *graph, int src, int dest)
{
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1; // Since it's an undirected graph
}

// Function to print the adjacency matrix
void printGraph(Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Create a graph with 5 vertices
    Graph graph;
    int numVertices = 5;
    initializeGraph(&graph, numVertices);

    // Add some edges
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    // Print the graph
    printGraph(&graph);

    return 0;
}
