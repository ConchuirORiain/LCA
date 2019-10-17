#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct graph* createGraph(int vertices);
void addEdge(struct graph* graph, int src, int dest);
void printGraph(struct graph* graph);
int *bfs(struct graph* graph, int startVertex);
struct node* createNode(int);

struct node{
    int vertex;
    struct node* next;
};

struct graph{
    int numVertices;
    struct node** adjLists;
    int* visited;
};


