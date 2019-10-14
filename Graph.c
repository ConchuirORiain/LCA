#include <stdio.h>
#include <stdlib.h>

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

int main(){
    return 0;
}
