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
