/*
��������ָ�룬fast��slow��fastÿ����������slowÿ����һ��.
��������л��Ƿ�յĻ�������ָ����������γ���һ��׷�����⣬�������������.
*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x),next(nullptr){}
};
#include<iostream>
using namespace std;

bool hasCycle(ListNode *node) {
	ListNode* fast;
	ListNode* slow;
	if (node == nullptr || node->next == nullptr) {
		return false;
	}
	slow = node;
	fast = node->next;
	while (fast!=nullptr)
	{
		if (fast == slow) {
			return true;
		}
		else
		{
			fast = fast->next;
			if (fast == nullptr) {
				return false;
			}
			else
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
	}
	return false;
}


void main() {
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node1;
	cout << hasCycle(node1);
	return;
}