#include "unity.h"
#include "LCA.h"

struct tree *graph;
struct tree *nullGraph;
struct tree *rightLeanGraph;
struct tree *leftLeanGraph;

void setUp(void){
	graph = newEmptyTree();
	nullGraph = newEmptyTree();
	rightLeanGraph = newEmptyTree();
	leftLeanGraph = newEmptyTree();

	graph->head = newNode(1);
	graph->head->left = newNode(2);
	graph->head->right = newNode(3);

	rightLeanGraph->head = newNode(1);
	rightLeanGraph->head->right = newNode(2);
	rightLeanGraph->head->right->right = newNode(3);
	rightLeanGraph->head->right->right->right = newNode(4);
	rightLeanGraph->head->right->right->right->right = newNode(5);
	rightLeanGraph->head->right->right->right->right->right = newNode(6);

	leftLeanGraph->head = newNode(1);
	leftLeanGraph->head->left = newNode(2);
	leftLeanGraph->head->left->left = newNode(3);
	leftLeanGraph->head->left->left->left = newNode(4);
	leftLeanGraph->head->left->left->left->left = newNode(5);
	leftLeanGraph->head->left->left->left->left->left = newNode(6);
}

void tearDown(void){
}

void testLCAFunction(void){
	TEST_ASSERT_EQUAL_MESSAGE(1,lca(graph->head,2,3)->data,"Basic graph, answer should be 1");
	TEST_ASSERT_NULL_MESSAGE(lca(nullGraph->head,2,3),"tree with no nodes, answer should be null");
	TEST_ASSERT_EQUAL_MESSAGE(5,lca(rightLeanGraph->head,5,6)->data,"long right leaning graph, answer should be 5");
	TEST_ASSERT_EQUAL_MESSAGE(5,lca(leftLeanGraph->head,5,6)->data,"long left leaning graph, answer should be 5");
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(testLCAFunction);
	return UNITY_END();
}
