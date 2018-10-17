#include<iostream>
#include<vector>
using namespace std;
/*
快速排序——前后指针法
1.定义变量cur指向序列的开头，定义变量pre指向cur的前一个位置。
2.当array[cur] < key时，cur和pre同时往后走，如果array[cur]>key，cur往后走，pre留在大于key的数值前一个位置。
3.当array[cur]再次 < key时，交换array[cur]和array[pre]。
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
归并排序:
拆分操作：
将数组拆分成A，B两个小组，接着A，B组各自再分成二组。依次类推，当分出来的小组只有一个数据时，
可以认为这个小组组内已经达到了有序，然后再合并相邻的二个小组就可以了。

合并数组操作：
1.比较二个数组的第一个数，谁小就先取谁，取了后就将对应数组的指针后移一位，然后再进行比较。
2.如果有数组指针为空，那直接将另一个数组的数据依次取出即可。
*/

//合并数组
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

//排序数组
void mergeSort(ListNode* &head, ListNode* &end) {
	if (head == end) {
		return;
	}

	ListNode* fast = head;
	ListNode* slow = head;
	//利用快慢指针找中间的节点
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