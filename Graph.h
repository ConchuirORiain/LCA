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

struct adjListNode *newAdjListNode(int aN);
struct graph *newGraph(int v);
void addEdge(struct graph *graph, int v, int w);

