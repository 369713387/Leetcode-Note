#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};
/*
��������һ��root���ʱ��

1.�ж�root�ǲ���null���rootΪnull����ô������ν���Ƚڵ㣬ֱ�ӷ���null�ͺ���

2.���root������������p������������q����ôroot�϶������������

3.���pq����root������������ô����Ҫ�ݹ�root����������������ͬ��
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || root==p || root == q) return root;
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	if (left && right) {
		return root;
	}
	else 
	{
		if (left) {
			return left;
		}
		else
		{
			return right;
		}
	}
}

void main() {
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t2 = new TreeNode(5);
	TreeNode* t3 = new TreeNode(1);

	TreeNode* t4 = new TreeNode(6);
	TreeNode* t5 = new TreeNode(2);

	TreeNode* t6 = new TreeNode(0);
	TreeNode* t7 = new TreeNode(8);

	TreeNode* t8 = new TreeNode(7);
	TreeNode* t9 = new TreeNode(4);

	t1->left = t2;
	t1->right = t3;

	t2->left = t4;
	t2->right = t5;

	t3->left = t6;
	t3->right = t7;

	t5->left = t8;
	t5->right = t9;

	TreeNode* root = t1;

	TreeNode* node = lowestCommonAncestor(root,t4,t7);
	return;
}