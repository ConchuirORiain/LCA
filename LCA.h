struct treeNode {
	int data;
	struct treeNode * left;
	struct treeNode * right;
};

struct tree{
	struct treeNode * head;
};

struct tree *newEmptyTree();
struct treeNode *newNode(int data);
struct treeNode *lca(struct treeNode* root, int n1, int n2); 
