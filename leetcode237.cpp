#include<iostream>
using namespace std;
/*
�������ٰ��������ڵ㡣
���������нڵ��ֵ����Ψһ�ġ�
�����Ľڵ�Ϊ��ĩβ�ڵ㲢��һ���������е�һ����Ч�ڵ㡣
��Ҫ����ĺ����з����κν����
˼·��
1.����Ҫɾ���Ľڵ��val��ֵΪ����next�ڵ�
2.ɾ������next�ڵ�
*/
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x),next(nullptr){}
};

void deleteNode(ListNode* node) {
	if (node == nullptr || node->next == nullptr) {
		return;
	}
	node->val = node->next->val;
	node->next = node->next->next;
}

void main() {
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	deleteNode(node2);
	ListNode* res = node1;
	return;
}