#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
	if (!root)
		return 0;

	return 1 + max(maxDepth(root->left),maxDepth(root->right));
}

void main() {
	TreeNode* root = new TreeNode(3);
	TreeNode* root1 = new TreeNode(9);
	TreeNode* root2 = new TreeNode(20);
	TreeNode* root3 = new TreeNode(15);
	TreeNode* root4 = new TreeNode(7);
	root->left = root1;
	root->right = root2;
	root2->left = root3;
	root2->right = root4;
	int res = maxDepth(root);
	return;
}