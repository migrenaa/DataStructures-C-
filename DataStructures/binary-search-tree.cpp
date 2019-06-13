
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

	void print(TreeNode* start) {
		if (start == NULL) {
			return;
		}
		cout << start->data << endl;
		if (start->left != NULL) {
			cout << "left: " << endl;
			print(start->left);

		}
		if (start->right != NULL) {
			cout << "right: " << endl;
			print(start->right);
		}
	}
	void add(int data, TreeNode* root) {
		if (root->data > data)
			if (root->left == NULL)
				root->left = new TreeNode(data);
			else
				add(data, root->left);
		else
			if (root->right == NULL)
				root->right = new TreeNode(data);
			else
				add(data, root->right);
	}
	TreeNode* search(TreeNode* start, int value) {
		if (start == NULL) {
			cout << "The element doesn't exist in the tree.";
			return NULL;
		}
		if (start->data == value) {
			return start;
		}
		if (start->data > value) {
			return search(start->left, value);
		}
		else {
			return search(start->right, value);
		}
	}

	void remove(TreeNode* r, int value) {
		if (r == NULL) {
			cout << "the element doesn't exist.";
			return;
		}
		if (value < r->data) remove(r->left, value);
		else if (value > r->data) remove(r->right, value);
		else {
			TreeNode* p;
			if (r->left == NULL) {
				p = r;
				r = r->right;
				delete p;
			}
			else if (r->right == NULL) {
				p = r;
				r = r->left;
				delete p;
			}
			else {
				p = r->left;
				while (p->right != NULL)
					p = p->right;
				r->data = p->data;
				remove(r->left, p->data);
			}
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

	void print() {
		print(root);
	}
	void add(int data) {
		add(data, root);
	}

	void remove(int value) {
		remove(root, value);
	}
	

	TreeNode* search(int value) {
		return search(root, value);
	}
};

int main() {
	TreeNode root(4);
	BinaryTree tree(&root);
	tree.add(2);
	tree.add(0);
	tree.add(1);
	tree.add(5);
	tree.add(6);
	tree.print();

	//TreeNode* n1 = tree.search(4);
	//TreeNode* n2 = tree.search(2);

	//cout << endl;
	//cout << n1->data << endl;
	//cout << n2->data << endl;

	tree.remove(2);
	cout << endl;

	tree.print();
	int a;
	cin >> a;
}
