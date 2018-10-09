#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};
/*
��������
1.������������ָ�룬Ȼ�����ν���������ÿһ�������������ĺ��档
2.Ȼ���������ͷָ��NewH�����µ�����ͷ��
3.����һ����ʱָ��tmp������ʱָ��P->nextָ��ĵ�ַ�ռ䣬����ԭ����������ݡ�
4.Ȼ������P->nextָ��NewH�����P=tmp�Ϳ���ȡ��ԭ����������ˣ�����ѭ������Ҳ���Լ���չ����ȥ��
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
�ݹ鷨��
1.��ѭ���ҵ������ָ�����5��Ȼ���5��ʼ�������η�ת��������
2.����ָ��H�������ף���������һ���µ�ָ����Ϊ��ת��������ͷ��������������ת֮���ͷ�������һ������������������NewHָ��һֱָ����5�ĵ�ַ�ռ䡣
3.Ȼ��Hָ����㷵�أ���Hָ��ĵ�ַ��ֵ��H->next->nextָ�룬����һ��Ҫ�ǵ���H->next =NULL��Ҳ���ǶϿ�����ָ������ӣ������µ������γ��˻�����һ��H->next->next��ֵ��ʱ��Ḳ�Ǻ�����ֵ��
4.���ص�ͷ�������
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