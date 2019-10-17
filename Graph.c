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
    enqueue(q,s);
    int distCount = 1;
    while(isEmpty(q) != 1){
        s = dequeue(q)->data;
        struct adjListNode *temp = graph->bag[s].head;
        while(temp){
            int adjVertex = temp->aN;
            if(visited[adjVertex] == 0){
                visited[adjVertex] = 1;
                visited[adjVertex + graph->v] =distCount;
                enqueue(q,adjVertex);
            }
            temp = temp->next;
        }
        distCount++;
    }
    return visited;
}
//
//int main(void){
//    struct graph *graph = newGraph(13);
//    addEdge(graph,12,10);
//    addEdge(graph,12,11);
//    addEdge(graph,11,9);
//    addEdge(graph,10,8);
//    addEdge(graph,9,7);
//    addEdge(graph,8,7);
//    addEdge(graph,7,6);
//    addEdge(graph,7,5);
//    addEdge(graph,6,4);
//    addEdge(graph,5,3);
//    addEdge(graph,4,2);
//    addEdge(graph,3,1);
//    addEdge(graph,2,0);
//    addEdge(graph,1,0);
//    int *array = BFS(graph,12);
//    for(int i = 0; i<13; i++)
//        printf("v:%d\tT:%d\tD:%d\n",i,array[i],array[i+13]);
//}
//
//
