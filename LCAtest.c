#include "unity.h"
#include "LCA.h"

struct graph *nullGraph;
struct graph *graph;
struct graph *nullGraph;
struct graph *rightLeanGraph;
struct graph *leftLeanGraph;
struct graph *complexGraph;
struct graph *simpleDAG;

void setUp(void){
	nullGraph = newEmptyGraph();
	graph = newEmptyGraph();
	nullGraph = newEmptyGraph();
	rightLeanGraph = newEmptyGraph();
	leftLeanGraph = newEmptyGraph();
	complexGraph = newEmptyGraph();
	simpleDAG = newEmptyGraph();

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
	
	simpleDAG->head = newNode(1);
	simpleDAG->head->left = newNode(2);
	simpleDAG->head->right = newNode(3);
	simpleDAG->head->left->left = newNode(4);
	simpleDAG->head->right->right = newNode(5);
	simpleDAG->head->left->left->right=newNode(6);
	simpleDAG->head->right->right->left = simpleDAG->head->left->left->right;
	simpleDAG->head->right->right->left->left = newNode(7);

}

void tearDown(void){
}

void testLCAFunction(void){
	TEST_ASSERT_EQUAL_PTR_MESSAGE(graph->head,lca(graph->head,2,3),"Basic graph, answer should be 1");
	TEST_ASSERT_NULL_MESSAGE(lca(nullGraph->head,2,3),"graph with no nodes, answer should be null");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(rightLeanGraph->head->right->right->right->right,
		lca(rightLeanGraph->head,5,6),"long right leaning graph, answer should be 5");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(leftLeanGraph->head->left->left->left->left,
		lca(leftLeanGraph->head,5,6),"long left leaning graph, answer should be 5");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(complexGraph->head->right,
		lca(complexGraph->head,756,12456),"more complex graph, answer should be 16");
}

void testLCAFunctionNULLDAG(void){
	TEST_ASSERT_NULL_MESSAGE(lca(nullGraph->head,4,5),"Null Graph answer should be null");
}
void testLCAFunctionSimpleDAG(void){
	TEST_ASSERT_EQUAL_PTR_MESSAGE(simpleDAG->head,lca(simpleDAG->head,2,3),"Simple query, answer should be 1");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(simpleDAG->head->left->left->right,
		lca(simpleDAG->head,6,7),"testing one way through cycle");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(simpleDAG->head->right->right->left,
		lca(simpleDAG->head,6,7),"testing second way through cycle");
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(testLCAFunction);
	RUN_TEST(testLCAFunctionNULLDAG);
	RUN_TEST(testLCAFunctionSimpleDAG);
	return UNITY_END();
}
