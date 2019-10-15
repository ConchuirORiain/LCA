#include "unity.h"
#include "LCA.h"

struct tree *nullTree;
struct tree *tree;
struct tree *nullTree;
struct tree *rightLeanTree;
struct tree *leftLeanTree;
struct tree *complexTree;

void setUp(void){
	nullTree = newEmptyTree();
	tree = newEmptyTree();
	nullTree = newEmptyTree();
	rightLeanTree = newEmptyTree();
	leftLeanTree = newEmptyTree();
	complexTree = newEmptyTree();

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
	
}

void tearDown(void){
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

int main(void){
	UNITY_BEGIN();
	RUN_TEST(testLCAFunction);
	return UNITY_END();
}
