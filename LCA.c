#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "LCA.h"

struct graphNode; 

struct graph;

struct graph *newEmptyGraph(){
	struct graph * result;
	result = malloc(sizeof(struct graph));
	result -> head = NULL;
	return result;
};

struct graphNode *newNode(int data){
	struct graphNode *result;
	result = malloc(sizeof(struct graphNode));
	result -> data = data;
	result -> left = NULL;
	result -> right = NULL;
	return result;
};	

struct graphNode *lca(struct graphNode* root, int n1, int n2) 
{ 
	if (root == NULL) return NULL; 
  
	if (root->data == n1 || root->data == n2) 
        return root;
  
	struct graphNode *leftLCA = lca(root->left,n1,n2);
	struct graphNode *rightLCA = lca(root->right,n1,n2);
	
	if(leftLCA != NULL && rightLCA != NULL) return root;
	return (leftLCA != NULL)? leftLCA : rightLCA;

	return root; 
}
