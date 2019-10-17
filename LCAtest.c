#include "unity.h"
#include "LCA.h"
#include "Graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct tree *nullTree;
struct tree *tree;
struct tree *nullTree;
struct tree *rightLeanTree;
struct tree *leftLeanTree;
struct tree *complexTree;
struct graph *nullGraph;
struct graph *simpleGraph;
struct graph *oneWayGraph;
struct graph *twoSetsGraph;
struct graph *threeSetsGraph;
struct graph *treeGraph;

void setUp(void){
	nullTree = newEmptyTree();
	tree = newEmptyTree();
	nullTree = newEmptyTree();
	rightLeanTree = newEmptyTree();
	leftLeanTree = newEmptyTree();
	complexTree = newEmptyTree();
    simpleGraph = createGraph(3);
    oneWayGraph = createGraph(8);
    twoSetsGraph = createGraph(8);
    threeSetsGraph = createGraph(10);
    treeGraph = createGraph(15);

	tree->head = newNode(1);
	tree->head->left = newNode(2);
	tree->head->right = newNode(3);

	rightLeanTree->head = newNode(1);
	rightLeanTree->head->right = newNode(2);
	rightLeanTree->head->right->right = newNode(3);
	rightLeanTree->head->right->right->right = newNode(4);
	rightLeanTree->head->right->right->right->right = newNode(5);
	rightLeanTree->head->right->right->right->right->right = newNode(6);

	leftLeanTree->head = newNode(1);
	leftLeanTree->head->left = newNode(2);
	leftLeanTree->head->left->left = newNode(3);
	leftLeanTree->head->left->left->left = newNode(4);
	leftLeanTree->head->left->left->left->left = newNode(5);
	leftLeanTree->head->left->left->left->left->left = newNode(6);

	complexTree->head = newNode(12);
	complexTree->head->right = newNode(16);
	complexTree->head->left = newNode(15);
	complexTree->head->left->left = newNode(23);
	complexTree->head->left->left->right = newNode(58);
	complexTree->head->left->left->right->right = newNode(402);
	complexTree->head->right->left = newNode(36);
	complexTree->head->right->left->right = newNode(64);
	complexTree->head->right->left->right->right = newNode(756);
	complexTree->head->right->right = newNode(45);
	complexTree->head->right->right->right = newNode(104);
	complexTree->head->right->right->left = newNode(93);
	complexTree->head->right->right->left->right = newNode(1052);
	complexTree->head->right->right->left->right->right = newNode(12456);

    addEdge(simpleGraph,1,0);
    addEdge(simpleGraph,2,0);

    addEdge(oneWayGraph,1,0);
    addEdge(oneWayGraph,2,1);
    addEdge(oneWayGraph,3,2);
    addEdge(oneWayGraph,4,3);
    addEdge(oneWayGraph,5,4);
    addEdge(oneWayGraph,6,5);
    addEdge(oneWayGraph,7,6);
    
    addEdge(twoSetsGraph,1,0);
    addEdge(twoSetsGraph,2,0);
    addEdge(twoSetsGraph,3,1);
    addEdge(twoSetsGraph,3,2);
    addEdge(twoSetsGraph,4,3);
    addEdge(twoSetsGraph,5,3);
    addEdge(twoSetsGraph,6,4);
    addEdge(twoSetsGraph,6,5);
    addEdge(twoSetsGraph,7,6);

    addEdge(threeSetsGraph,1,0);
    addEdge(threeSetsGraph,2,0);
    addEdge(threeSetsGraph,3,1);
    addEdge(threeSetsGraph,3,2);
    addEdge(threeSetsGraph,4,1);
    addEdge(threeSetsGraph,4,3);
    addEdge(threeSetsGraph,5,2);
    addEdge(threeSetsGraph,6,4);
    addEdge(threeSetsGraph,7,5);
    addEdge(threeSetsGraph,8,6);
    addEdge(threeSetsGraph,8,7);
    addEdge(threeSetsGraph,9,8);

    addEdge(treeGraph,1,0);
    addEdge(treeGraph,2,0);
    addEdge(treeGraph,3,1);
    addEdge(treeGraph,4,1);
    addEdge(treeGraph,5,2);
    addEdge(treeGraph,6,2);
    addEdge(treeGraph,7,3);
    addEdge(treeGraph,8,3);
    addEdge(treeGraph,9,4);
    addEdge(treeGraph,10,4);
    addEdge(treeGraph,11,5);
    addEdge(treeGraph,12,5);
    addEdge(treeGraph,13,6);
    addEdge(treeGraph,14,6);

}

void tearDown(void){
    clearTree(tree->head);
    clearTree(nullTree->head);
    clearTree(rightLeanTree->head);
    clearTree(leftLeanTree->head);
    clearTree(complexTree->head);
    
}

void testLCAFunction(void){
	TEST_ASSERT_EQUAL_PTR_MESSAGE(tree->head,lca(tree->head,2,3),"Basic tree, answer should be 1");
	TEST_ASSERT_NULL_MESSAGE(lca(nullTree->head,2,3),"tree with no nodes, answer should be null");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(rightLeanTree->head->right->right->right->right,
		lca(rightLeanTree->head,5,6),"long right leaning tree, answer should be 5");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(leftLeanTree->head->left->left->left->left,
		lca(leftLeanTree->head,5,6),"long left leaning tree, answer should be 5");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(complexTree->head->right,
		lca(complexTree->head,756,12456),"more complex tree, answer should be 16");
}

void testNull(void){
    TEST_ASSERT_NULL_MESSAGE(nullGraph,"should be null");
}


void testbfs(void){
    TEST_ASSERT_EQUAL_MESSAGE(-1,bfs(simpleGraph,1)[2],"doesn't visit 2 so answer should be -1");
    TEST_ASSERT_LESS_THAN_MESSAGE(bfs(simpleGraph,1)[0],bfs(simpleGraph,1)[1],"visits 1 first so should be of lower order than 0");
    TEST_ASSERT_LESS_THAN(bfs(simpleGraph,2)[0],bfs(simpleGraph,2)[2]);
    TEST_ASSERT_LESS_THAN(bfs(oneWayGraph,1)[0],bfs(simpleGraph,1)[1]);
    TEST_ASSERT_LESS_THAN(bfs(twoSetsGraph,3)[1],bfs(twoSetsGraph,3)[3]);
    TEST_ASSERT_LESS_THAN(bfs(threeSetsGraph,7)[0],bfs(threeSetsGraph,7)[2]);
    TEST_ASSERT_LESS_THAN(bfs(threeSetsGraph,9)[1],bfs(threeSetsGraph,9)[8]);
    TEST_ASSERT_LESS_THAN(bfs(treeGraph,14)[0],bfs(treeGraph,14)[2]);
}

void testDAGLCA(void){
    TEST_ASSERT_EQUAL(1,DAGLCA(simpleGraph,0,1));
    TEST_ASSERT_EQUAL(0,DAGLCA(simpleGraph,0,0));
    TEST_ASSERT_EQUAL(1,DAGLCA(oneWayGraph,7,1));
    TEST_ASSERT_EQUAL(5,DAGLCA(twoSetsGraph,7,5));
    //TEST_ASSERT_EQUAL(3,DAGLCA(twoSetsGraph,1,2));
    //TEST_ASSERT_EQUAL(2,DAGLCA(threeSetsGraph,4,5));
    TEST_ASSERT_EQUAL(5,DAGLCA(threeSetsGraph,6,7));
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(testLCAFunction);
    RUN_TEST(testNull);
    RUN_TEST(testbfs);
    RUN_TEST(testDAGLCA);
	return UNITY_END();
}
