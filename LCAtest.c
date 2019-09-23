#include "unity.h"
#include "LCA.h"

struct tree *graph;
void setUp(void){
	graph = newEmptyTree();
	graph->head = newNode(1);
	graph->head->left = newNode(2);
	graph->head->right = newNode(3);
}

void tearDown(void){
}

void testLCAFunction(void){
	TEST_ASSERT_EQUAL(1,lca(graph->head,2,3)->data);
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(testLCAFunction);
	return UNITY_END();
}
