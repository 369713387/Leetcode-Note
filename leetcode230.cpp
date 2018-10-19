#include<stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

/*
思路：
1.题目中给定的条件是BST，节点大小是左<中<右
2.中序遍历该二叉树，遍历到第k个节点时，返回该节点的值
*/

int kthSmallest(TreeNode* root, int k) {
	stack<TreeNode*> s;
	s.push(root);
	TreeNode* newTree = root;
	int count = 0;
	while (!s.empty()||newTree!=NULL)
	{
		while (newTree!=NULL) {
			s.push(newTree);
			newTree = newTree->left;
		}
		newTree = s.top();
		s.pop();
		count++;
		if (k == count) {
			return newTree->val;
		}
		newTree = newTree->right;
	}
}

void main() {
	TreeNode* root = new TreeNode(4);
	TreeNode* root1 = new TreeNode(3);
	TreeNode* root2 = new TreeNode(2);
	TreeNode* root3 = new TreeNode(1);	
	root1->left = root3;
	root1->right = root;
	root3->right = root2;
	int res = kthSmallest(root1,1);
	return;
}
