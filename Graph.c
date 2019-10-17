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

int *bfs(struct graph* graph, int startVertex){
    struct queue* q = createQueue();
    
    graph->visited[startVertex] = 0;
    enqueue(q, startVertex);
    int visitOrder = 1;
    while(!isEmpty(q)){
        printQueue(q);
        int currentVertex = dequeue(q);
   
       struct node* temp = graph->adjLists[currentVertex];
    
       while(temp) {
            int adjVertex = temp->vertex;
            printf("aV:%d\n",adjVertex);
            if(graph->visited[adjVertex] <= visitOrder){
                graph->visited[adjVertex] = visitOrder;
                enqueue(q, adjVertex);
                visitOrder++;
            }
            temp = temp->next;
       }
    }
    return(graph->visited);
}
 
struct node* createNode(int v){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
 
struct graph* createGraph(int vertices){
    struct graph* graph = malloc(sizeof(struct graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = -1;
    }
 
    return graph;
}
 
void addEdge(struct graph* graph, int src, int dest){
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
}
