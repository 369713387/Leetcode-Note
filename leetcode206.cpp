#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};
/*
迭代法：
1.首先设置两个指针，然后依次将旧链表上每一项添加在新链表的后面。
2.然后新链表的头指针NewH移向新的链表头。
3.设置一个临时指针tmp，先暂时指向P->next指向的地址空间，保存原链表后续数据。
4.然后再让P->next指向NewH，最后P=tmp就可以取回原链表的数据了，所有循环访问也可以继续展开下去。
*/
ListNode* reverseList(ListNode* node) {
	if (node == nullptr || node->next == nullptr) {
		return node;
	}
	ListNode* p = node;
	ListNode* newNode = nullptr;
	while (p!=nullptr)
	{
		ListNode* tmp = p->next;
		p->next = newNode;
		newNode = p;
		p = tmp;
	}
	return newNode;
}
/*
递归法：
1.先循环找到最后面指向的数5，然后从5开始处理依次翻转整个链表。
2.首先指针H迭代到底，并且设置一个新的指针作为翻转后的链表的头。由于整个链表翻转之后的头就是最后一个数，所以整个过程NewH指针一直指向存放5的地址空间。
3.然后H指针逐层返回，将H指向的地址赋值给H->next->next指针，并且一定要记得让H->next =NULL，也就是断开现在指针的链接，否则新的链表形成了环，下一层H->next->next赋值的时候会覆盖后续的值。
4.返回到头即可完成
*/

ListNode* In_reverseList(ListNode* node) {
	if (node == nullptr || node->next == nullptr) {
		return node;
	}
	
	ListNode* newNode = In_reverseList(node->next);
	node->next->next = node;
	node->next = nullptr;
	return newNode;
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
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = nullptr;
	ListNode* node = node1;
	node = In_reverseList(node);
	return;
}