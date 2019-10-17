#ifndef _LCAH_
#define _LCAH_
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "queue.h"

struct treeNode {
	int data;
	struct treeNode * left;
	struct treeNode * right;
};

struct tree{
	struct treeNode * head;
};

struct tree *newEmptyTree();
struct treeNode *newNode(int data);
struct treeNode *lca(struct treeNode* root, int n1, int n2); 
void clearTree(struct treeNode *root);
int DAGLCA(struct graph *graph, int x, int y);
#endif
