#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "LCA.h"
#include "Graph.h"
#include "queue.h"

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

int DAGLCA(struct graph *graph, int x, int y){
    int *bfsArrayX = bfs(graph, x);
    int *bfsArrayY = bfs(graph, y);
    int currentLCA = -1;
    int dist = 0;
    for(int i = 0; i<graph->numVertices; i++)
        printf("bA%d\tv:%d\td:%d\tbA%d\tv:%d\td:%d\n",x,i,bfsArrayX[i],y,i,bfsArrayY[i]);
    for(int i = 0; i<graph->numVertices; i++){
        printf("XV:%d\tXD:%d\nYV:%d\tYD:%d\n\n",i,bfsArrayX[i],i,bfsArrayY[i]);
        if(bfsArrayX[i] != -1 && bfsArrayY[i] != -1){
            if(currentLCA == -1){
                currentLCA = i;
                dist = bfsArrayX[i] + bfsArrayY[i];
            }
            else if(dist > (bfsArrayX[i] + bfsArrayY[i])){
                dist = bfsArrayX[i] + bfsArrayY[i];
                currentLCA = i;
            }
        }
    }
    return currentLCA;
}


