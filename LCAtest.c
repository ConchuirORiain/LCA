#include "unity.h"
#include "LCA.h"

void setUp(void){
	struct tree *graph = newEmptyTree();
	struct tree graph->head = newNode(1);
	struct tree graph->head->left = newNode(2);
	struct tree graph->head->right = newNode(3);
}

void tearDown(void){
}

void testLCAFunction(void){
	TEST_ASSERT_EQUAL(1,lca(graph->head,2,3);
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(testLCAfunction);
	return UNITY_END();
}
