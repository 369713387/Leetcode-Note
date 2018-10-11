/*
设置两个指针，fast和slow，fast每次走两步，slow每次走一步.
如果链表有环是封闭的话，两个指针在里面就形成了一个追击问题，是早晚会相遇的.
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