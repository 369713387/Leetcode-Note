/*
1.���ȱ������������¼�����ǵĳ���LenA��LenB��
2.���߳��Ȳ�Ϊmovelen,�����ڽ��㣬 ������һ����㵽�����λ����������Ľ����һ������ͬ�ġ�
3.����ʹ�ϳ�������������ƶ�x��λ�ã�ʹ���������ĳ������������ͬ����
4.�ٿ�ʼ����������ͬʱ���б�����ֱ����������һ����ͬ���ʱ��Ϊ���㡣
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	//1.
	ListNode* A = headA;
	ListNode* B = headB;
	int LenA = 0, LenB = 0;
	while (A != nullptr)
	{
		A = A->next;
		LenA++;
	}

	while (B != nullptr)
	{
		B = B->next;
		LenB++;
	}
	//2.
	int movelen = abs(LenB - LenA);
	//3.
	if (LenA > LenB) {
		for (int i = 0; i < movelen; i++)
		{
			headA = headA->next;
		}
	}
	else
	{
		for (int i = 0; i < movelen; i++)
		{
			headB = headB->next;
		}
	}
	//4.
	int count = 0;
	while (headA != nullptr && headB != nullptr)
	{
		if (headA == headB) {
			return headA;
		}
		else
		{
			headA = headA->next;
			headB = headB->next;
		}
	}

}


void main() {
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	ListNode* node7 = new ListNode(7);
	ListNode* node8 = new ListNode(8);
	ListNode* node9 = new ListNode(9);

	node1->next = node2;
	node2->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = node5;	
	
	node3->next = node4;
	node4->next = node5;

	node5->next = node6;

	ListNode* res = getIntersectionNode(node1, node3);
	return;
}