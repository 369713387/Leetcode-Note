#include<iostream>
#include<vector>
using namespace std;
/*
�������򡪡�ǰ��ָ�뷨
1.�������curָ�����еĿ�ͷ���������preָ��cur��ǰһ��λ�á�
2.��array[cur] < keyʱ��cur��preͬʱ�����ߣ����array[cur]>key��cur�����ߣ�pre���ڴ���key����ֵǰһ��λ�á�
3.��array[cur]�ٴ� < keyʱ������array[cur]��array[pre]��
*/
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* GetPartion(ListNode* pBegin, ListNode* pEnd) {
	int key = pBegin->val;
	ListNode* pre = pBegin;
	ListNode* cur = pBegin->next;

	while (cur!=pEnd)
	{
		if (cur->val < key) {						
			pre = pre->next;
			swap(pre->val, cur->val);
		}
		cur = cur->next;
	}
	swap(pre->val, pBegin->val);
	return pre;
}

void QuickSort(ListNode* pBegin,ListNode* pEnd) {
	if (pBegin != pEnd) {
		ListNode* partion = GetPartion(pBegin, pEnd);
		QuickSort(pBegin, partion);
		QuickSort(partion->next, pEnd);
	}	
}

/*
�鲢����:
��ֲ�����
�������ֳ�A��B����С�飬����A��B������ٷֳɶ��顣�������ƣ����ֳ�����С��ֻ��һ������ʱ��
������Ϊ���С�������Ѿ��ﵽ������Ȼ���ٺϲ����ڵĶ���С��Ϳ����ˡ�

�ϲ����������
1.�Ƚ϶�������ĵ�һ������˭С����ȡ˭��ȡ�˺�ͽ���Ӧ�����ָ�����һλ��Ȼ���ٽ��бȽϡ�
2.���������ָ��Ϊ�գ���ֱ�ӽ���һ���������������ȡ�����ɡ�
*/

//�ϲ�����
void merge(ListNode* &head, ListNode* &mid, ListNode* &end) {
	if (head == mid && mid == end) {
		return;
	}
	ListNode* p = head;
	ListNode* p1 = mid->next;
	vector<int> vec;
	int len = 0;
	//1.
	while (p != mid->next && p1 != end->next)
	{
		if (p->val <= p1->val) {
			vec.push_back(p->val);
			len++;
			p = p->next;
		}
		else
		{
			vec.push_back(p1->val);
			len++;
			p1 = p1->next;
		}
	}

	while (p != mid->next) {
		vec.push_back(p->val);
		len++;
		p = p->next;
	}

	while (p1 != end->next)
	{
		vec.push_back(p1->val);
		len++;
		p1 = p1->next;
	}

	ListNode* p2 = head;
	for (int i = 0; i < len; i++)
	{
		p2->val = vec[i];
		p2 = p2->next;
	}
}

//��������
void mergeSort(ListNode* &head, ListNode* &end) {
	if (head == end) {
		return;
	}

	ListNode* fast = head;
	ListNode* slow = head;
	//���ÿ���ָ�����м�Ľڵ�
	while (fast!=end)
	{
		if (fast->next != end) {
			fast = fast->next->next;
		}
		else
		{
			break;
		}
		slow = slow->next;
	}
	
	ListNode* mid = slow;

	if (head != mid) {
		mergeSort(head, mid);
	}

	if(mid!=end)
	{
		mergeSort(mid->next, end);
	}

	merge(head, mid, end);
}

ListNode* sortList(ListNode* head) {
	//QuickSort(head,NULL);
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode* end = head;
	while (end->next != NULL)
	{
		end = end ->next;
	}
	mergeSort(head, end);
	return head;
}

void main() {
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(7);
	ListNode* node5 = new ListNode(6);
	ListNode* node6 = new ListNode(5);
	ListNode* node7 = new ListNode(4);
	ListNode* node8 = new ListNode(8);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	ListNode* res = sortList(node1);
	return;
}