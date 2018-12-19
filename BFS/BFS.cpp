#include<queue>
#include<iostream>
using namespace std;

struct TreeNode{
	int data;
	TreeNode* leftchild;
	TreeNode* rightchild;
	
	TreeNode(int value){
		data = value;
		leftchild = NULL;
		rightchild = NULL;
	}
};

int BFS(TreeNode* root,TreeNode* target){
	queue<TreeNode*> q;
	int step = 0;
	q.push(root);
	while(!q.empty()){
		step += 1;
		int size = q.size();
		for(int i = 0;i<size;i++){
			TreeNode* current = q.front();
			cout<<"根节点"<<current->data<<" ";
			if(current == target){
				return step;
			}
			//遍历左子树
			if(current->leftchild!=NULL){
				q.push(current->leftchild);
				cout<<"左子树"<<current->leftchild->data<<" ";
			}
			//遍历右子树 
			if(current->rightchild!=NULL){
				q.push(current->rightchild);
				cout<<"右子树"<<current->rightchild->data<<" ";
			}
			q.pop();
		}
	}
	return -1;
}

int main(){
	TreeNode* root = new TreeNode(0);
	root->leftchild = new TreeNode(1);
	root->rightchild = new TreeNode(2);
	root->leftchild->leftchild = new TreeNode(3);
	root->leftchild->rightchild = new TreeNode(4);
	root->rightchild->leftchild = new TreeNode(5);
	root->rightchild->rightchild = new TreeNode(6);
	int res = BFS(root,root->leftchild->rightchild);
	cout<< res<<endl;
	cout<<root->data<<" "<<root->leftchild->data<<" "<<root->rightchild->data<<" "<<root->leftchild->leftchild->data<<" "<<root->leftchild->rightchild->data<<endl;	
	return 0;
}
