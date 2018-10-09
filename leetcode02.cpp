/*
思路:
输入两个链表，输出一个链表。则需要新建一个链表.
把输入的两个链表从头开始，每两个数值相加，添加一个新节点到新链表后面。
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* result = new ListNode(0);
	ListNode* tmp = result;
	int sum = 0;
	while (l1||l2)
	{
		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			sum += l2->val;
			l2 = l2->next;
		}
		tmp->next = new ListNode(sum % 10);
		sum /= 10;
		tmp = tmp->next;
	}
	if (sum) {
		tmp->next = new ListNode(1);
	}
	return result->next;
}

void main() {
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	node1->next = node2;
	node2->next = node3;
	//node2->next->next = nullptr;
	node3 = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = nullptr;
	ListNode* l1 = node1;
	ListNode* l2 = node3;
	ListNode* res = addTwoNumbers(l1, l2);
	return;
}