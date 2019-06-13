
#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left, *right;
	TreeNode(int _data = 0,
		TreeNode* _left = NULL,
		TreeNode* _right = NULL)
		: data(_data), left(_left), right(_right) {}
};

class BinaryTree {
private:
	TreeNode* root;

	TreeNode* copyNode(TreeNode* n) {
		if (n == NULL)
			return n;
		return new TreeNode(n->data, copyNode(n->left),
			copyNode(n->right));
	}
	void eraseNode(TreeNode* node) {
		if (node != NULL) {
			eraseNode(node->left);
			eraseNode(node->right);
			delete node;
		}
	}
public:
	BinaryTree(TreeNode* p) : root(copyNode(p)) {}
	BinaryTree(int x, BinaryTree const& left, BinaryTree const& right) : root(new TreeNode(x, copyNode(left.root), copyNode(right.root))) {
	}

	int getRoot() {
		if (empty()) {
			cout << "The tree is empty";
			return 0;
		}
		return root->data;
	}

	BinaryTree leftTree() const {
		return BinaryTree(root->left);
	}

	BinaryTree rightTree() const {
		return BinaryTree(root->right);
	}

	bool empty() {
		return root == NULL;
	}

	~BinaryTree() {
		eraseNode(root);
	}
};
