#include<iostream>
using namespace std;
/*
链表至少包含两个节点。
链表中所有节点的值都是唯一的。
给定的节点为非末尾节点并且一定是链表中的一个有效节点。
不要从你的函数中返回任何结果。
思路：
1.将想要删除的节点的val赋值为它的next节点
2.删除它的next节点
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