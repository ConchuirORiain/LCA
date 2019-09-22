#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

struct treeNode {
	int data;
	struct treeNode * left;
	struct treeNode * right;
};

struct tree{
	struct treeNode * head;
};

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
  
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 
  
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
}
 
int main(){
	struct tree *graph = newEmptyTree();
	graph->head = newNode(1);
	graph->head->left = newNode(2);
	graph->head->right = newNode(3);
	struct treeNode *ancestor = lca(graph->head, 2, 3);
	printf("root %d\n", graph->head->data);
	printf("left %d\n", graph->head->left->data);
	printf("right %d\n", graph->head->right->data);
	printf("lca: %d\n", ancestor -> data);
}
