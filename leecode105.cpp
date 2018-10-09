#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

TreeNode* createTree(vector<int> preorder, vector<int> inorder, int pLeft, int pRight, int iLeft, int iRight) {
	if (pLeft>pRight) {
		return NULL;
	}
	TreeNode* root = new TreeNode(preorder[pLeft]);
	int idx = iLeft;
	while (inorder[idx] != preorder[pLeft]) {
		idx++;
	}
	root->left = createTree(preorder, inorder, pLeft + 1, pLeft + idx - iLeft, iLeft, idx - 1);
	cout << "root->left: pLeft : " << pLeft << "  pRight : " << pRight << "  iLeft : " << iLeft << "   iRight : " << iRight << "   root: " << root->val << endl;
	root->right = createTree(preorder, inorder, pLeft + idx - iLeft + 1, pRight, idx + 1, iRight);
	cout << "root->right: pLeft : " << pLeft << "  pRight : " << pRight << "  iLeft : " << iLeft << "  iRight : " << iRight << "   root: " << root->val << endl;
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return createTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main() {
	vector<int> p = { 3,9,20,15,7 };
	vector<int> i = { 9,3,15,20,7 };
	TreeNode* root = buildTree(p,i);
	int x;
	cin >> x;
}