struct graphNode {
	int data;
	struct graphNode * left;
	struct graphNode * right;
};

struct graph{
	struct graphNode * head;
};

struct graph *newEmptyGraph();
struct graphNode *newNode(int data);
struct graphNode *lca(struct graphNode* root, int n1, int n2); 
