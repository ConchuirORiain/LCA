#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "LCA.h"
#include "Graph.h"

struct treeNode; 

struct tree;

struct tree *newEmptyTree(){
	struct tree * result;
	result = malloc(sizeof(struct tree));
	result -> head = NULL;
	return result;
};

struct treeNode *newNode(int data){
	struct treeNode *result;
	result = malloc(sizeof(struct treeNode));
	result -> data = data;
	result -> left = NULL;
	result -> right = NULL;
	return result;
};	

struct treeNode *lca(struct treeNode* root, int n1, int n2) 
{ 
	if (root == NULL) return NULL; 
 
	if (root->data == n1 || root->data == n2) 
        return root;
  
	struct treeNode *leftLCA = lca(root->left,n1,n2);
	struct treeNode *rightLCA = lca(root->right,n1,n2);
	
	if(leftLCA != NULL && rightLCA != NULL) return root;
	return (leftLCA != NULL)? leftLCA : rightLCA;

	return root; 
}

void clearTree(struct treeNode *root){
    if(root == NULL)
        return;
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

int lcaDAG(struct graph *graph, int x, int y){
    for(int i = 0 ; i < graph->v;i++){
		struct adjListNode *pCrawl = graph->bag[i].head;
		if(contains(pCrawl,x)==1)
			for(int j = 0 ; j < graph->v;j++){
				pCrawl = graph->bag[j].head;
				if(contains(pCrawl,y)==1)
					return i;
			}
		if(contains(pCrawl,y)==1)
			for(int j = 0 ; j < graph->v;j++){
				pCrawl = graph->bag[j].head;
				if(contains(pCrawl,x)==1)
					return i;
			}
	}
	return -1;
}

int main(void){
    struct graph *graph = newGraph(15);

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,5);
    addEdge(graph,2,6);
    addEdge(graph,3,7);
    addEdge(graph,3,8);
    addEdge(graph,4,9);
    addEdge(graph,4,10);
    addEdge(graph,5,11);
    addEdge(graph,5,12);
    addEdge(graph,6,13);
    addEdge(graph,6,14);

    printf("9,14: %d\nshould be 0\n",lcaDAG(graph,9,14));
}
