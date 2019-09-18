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
	result -> left = NULL;
	result -> right = NULL;
	return result;
};	

int main(){
	struct tree *graph = newEmptyTree();
}
