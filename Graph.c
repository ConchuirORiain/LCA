#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct graph{
    int v;
    struct adjList *bag;
};

struct adjList{
    struct adjListNode *head;
};

struct adjListNode{
    int aN;
    struct adjListNode *next;
};

struct adjListNode *newAdjListNode(int aN){
    struct adjListNode *result = malloc(sizeof(struct adjListNode));
    result -> aN = aN;
    result -> next = NULL;
    return result;
};

struct graph *newGraph(int v){
    struct graph *result = malloc(sizeof(struct graph));
    result -> v = v;
    result -> bag = (struct adjList *) malloc(v * sizeof(struct adjList));
    for(int i =0; i<v; ++i){
        result-> bag[i].head = NULL;
    }
    return result;
};

void addEdge(struct graph *graph, int v, int w){
    struct adjListNode *added = newAdjListNode(w);
    added-> next = graph->bag[v].head;
    graph->bag[v].head = added;
};

int contains(struct adjListNode *node, int dest){
       while(node){
            if(node->aN == dest)
               return 1;
            node = node-> next;
       }
       return 0;
}

int *BFS(struct graph* graph, int s){
   int *visited = malloc(2*graph->v*(sizeof(int)));
   for(int i =0; i < graph->v; i++)
       visited[i] = 0;
    for(int i = graph->v; i < 2*graph->v; i++)
        visited[i] = - 1;
    visited[s] = 1;
    visited[s+graph->v] = 0;
    struct queue *q = newEmptyQueue();
    int check = enqueue(q,s);
    if(check != 1) exit(check);
    int distCount = 1;
    while(isEmpty(q) != 1){
        s = dequeue(q)->data;
        for(int i = 0; i < graph->v; i++){
            if(contains(graph->bag[s].head, i) == 1 && visited[i] == 0){
                visited[i] = 1;
                visited[i + graph -> v] = distCount;
                check = enqueue(q,i);
                if(check != 1) exit(check);
            }
        }
        distCount++;
    }
    return visited;
}
