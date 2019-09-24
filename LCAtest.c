#include "unity.h"
#include "LCA.h"

struct tree *graph;
struct tree *nullGraph;
struct tree *rightLeanGraph;
struct tree *leftLeanGraph;
struct tree *complexGraph;

void setUp(void){
	graph = newEmptyTree();
	nullGraph = newEmptyTree();
	rightLeanGraph = newEmptyTree();
	leftLeanGraph = newEmptyTree();
	complexGraph = newEmptyTree();

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

	complexGraph->head = newNode(12);
	complexGraph->head->right = newNode(16);
	complexGraph->head->left = newNode(15);
	complexGraph->head->left->left = newNode(23);
	complexGraph->head->left->left->right = newNode(58);
	complexGraph->head->left->left->right->right = newNode(402);
	complexGraph->head->right->left = newNode(36);
	complexGraph->head->right->left->right = newNode(64);
	complexGraph->head->right->left->right->right = newNode(756);
	complexGraph->head->right->right = newNode(45);
	complexGraph->head->right->right->right = newNode(104);
	complexGraph->head->right->right->left = newNode(93);
	complexGraph->head->right->right->left->right = newNode(1052);
	complexGraph->head->right->right->left->right->right = newNode(12456);

}

void tearDown(void){
}

void testLCAFunction(void){
	TEST_ASSERT_EQUAL_MESSAGE(1,lca(graph->head,2,3)->data,"Basic graph, answer should be 1");
	TEST_ASSERT_NULL_MESSAGE(lca(nullGraph->head,2,3),"tree with no nodes, answer should be null");
	TEST_ASSERT_EQUAL_MESSAGE(5,lca(rightLeanGraph->head,5,6)->data,"long right leaning graph, answer should be 5");
	TEST_ASSERT_EQUAL_MESSAGE(5,lca(leftLeanGraph->head,5,6)->data,"long left leaning graph, answer should be 5");
	TEST_ASSERT_EQUAL_MESSAGE(16,lca(complexGraph->head,756,12456)->data,"more complex graph, answer should be 16");
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(testLCAFunction);
	return UNITY_END();
}
