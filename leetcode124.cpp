#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

/*
路径和的所有可能性：
1)root
2)root+左边某条路径
3)root+右边某条路径
4)root+左边某条路径+右边某条路径
*/

int maxVal = INT_MIN;

int maxPathSum(TreeNode* root) {
	if (!root) return 0;
	int left = max(maxPathSum(root->left), 0);
	int right = max(maxPathSum(root->right), 0);
	maxVal = max(maxVal, left + right + root->val);  // 下级的暂时结果;
	return max(left, right) + root->val;  // 反馈到上级的一边;
}

void main() {
	TreeNode *r1 = new TreeNode(-3);
	TreeNode *r2 = new TreeNode(-9);
	TreeNode *r3 = new TreeNode(20);
	TreeNode *r4 = new TreeNode(-25);
	TreeNode *r5 = new TreeNode(7);
	TreeNode *r6 = new TreeNode(14);
	r1->left = r2;
	r1->right = r3;
	r2->left = r4;
	r3->right = r5;
	r3->left = r6;
	maxPathSum(r1);
	int res = maxVal;
	return;
}