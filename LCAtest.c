#include "unity.h"
#include "LCA.h"
#include "Graph.h"
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
    simpleGraph = newGraph(3);
    oneWayGraph = newGraph(8);
    twoSetsGraph = newGraph(11);
    threeSetsGraph = newGraph(12);
    treeGraph = newGraph(15);

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
    addEdge(twoSetsGraph,4,2);
    addEdge(twoSetsGraph,5,3);
    addEdge(twoSetsGraph,6,4);
    addEdge(twoSetsGraph,7,5);
    addEdge(twoSetsGraph,7,6);
    addEdge(twoSetsGraph,8,7);
    addEdge(twoSetsGraph,9,7);
    addEdge(twoSetsGraph,10,8);
    addEdge(twoSetsGraph,11,9);
    addEdge(twoSetsGraph,12,10);
    addEdge(twoSetsGraph,12,11);


    addEdge(threeSetsGraph,1,0);
    addEdge(threeSetsGraph,2,0);
    addEdge(threeSetsGraph,3,1);
    addEdge(threeSetsGraph,3,2);
    addEdge(threeSetsGraph,4,1);
    addEdge(threeSetsGraph,4,3);
    addEdge(threeSetsGraph,5,2);
    addEdge(threeSetsGraph,6,5);
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

void testContains(void){
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(simpleGraph->bag[1].head,0),"true, return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(simpleGraph->bag[2].head,0),"true,return 1");

    TEST_ASSERT_EQUAL_MESSAGE(1,contains(oneWayGraph->bag[1].head,0),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(oneWayGraph->bag[2].head,1),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(oneWayGraph->bag[3].head,2),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(oneWayGraph->bag[4].head,3),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(oneWayGraph->bag[5].head,4),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(oneWayGraph->bag[6].head,5),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(oneWayGraph->bag[7].head,6),"true,return 1");

    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[1].head,0),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[2].head,0),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[3].head,1),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[4].head,2),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[5].head,3),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[6].head,4),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[7].head,5),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[7].head,6),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[8].head,7),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[9].head,7),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[10].head,8),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[11].head,9),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[12].head,10),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(twoSetsGraph->bag[12].head,11),"true,return 1");

    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[1].head,0),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[2].head,0),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[3].head,1),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[3].head,2),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[4].head,1),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[4].head,3),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[5].head,2),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[6].head,5),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[7].head,5),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[8].head,6),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[8].head,7),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(threeSetsGraph->bag[9].head,8),"true,return 1");

    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[1].head,0),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[2].head,0),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[3].head,1),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[4].head,1),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[5].head,2),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[6].head,2),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[7].head,3),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[8].head,3),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[9].head,4),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[10].head,4),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[11].head,5),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[12].head,5),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[13].head,6),"true,return 1");
    TEST_ASSERT_EQUAL_MESSAGE(1,contains(treeGraph->bag[14].head,6),"true,return 1");
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(testLCAFunction);
    RUN_TEST(testNull);
    RUN_TEST(testContains);
	return UNITY_END();
}
