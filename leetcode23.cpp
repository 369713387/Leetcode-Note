/*
˼·һ��
��K����������нڵ�ֵ���뵽һ�������У�Ȼ���������������ٹ���һ���µ��������䷵�ء�
˼·��:
���˼·һ����ʹ�������ȶ��У���Ϊʹ�������ȶ��У��Ƚ϶���ΪListNode��Ҳ���������Լ�������ࡣ
*/
#include<list>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class myCompare {
public:
	bool operator()(ListNode* node1, ListNode* node2){
		return node1->val >= node2->val;
	}
};

ListNode* mergeKLists(vector<ListNode*>&lists) {
	ListNode* result = new ListNode(0);
	ListNode* head = result;
	list<int> valls = list<int>();
	for (int i = 0; i < lists.size(); i++)
	{
		while (lists[i]) {
			valls.push_back(lists[i]->val);
			lists[i] = lists[i]->next;
		}
	}
	valls.sort();
	for (list<int>::iterator it = valls.begin(); it != valls.end() ; it++)
	{
		head->next = new ListNode(*it);
		head = head->next;
	}
	return result->next;
}

ListNode* mergeKlists_Ver2(vector<ListNode*> lists) {
	ListNode* result = new ListNode(0);
	ListNode* head = result;
	priority_queue<ListNode*, vector<ListNode*>, myCompare>q;
	for (int i = 0; i < lists.size(); i++)
	{
		if (lists[i] != NULL) {
			q.push(lists[i]);
		}
	}

	while (!q.empty())
	{
		ListNode* current = q.top();
		q.pop();
		head->next = new ListNode(current->val);
		head = head->next;
		current = current->next;
		if (current != nullptr) {
			q.push(current);
		}
	}

	return result->next;
}


void main() {
	ListNode* node1 = new ListNode(3);
	ListNode* node2 = new ListNode(1);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(2);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(4);
	ListNode* node7 = new ListNode(9);
	ListNode* node8 = new ListNode(4);

	node1->next = node2;
	node2->next = node3;
	node4->next = node5;
	node5->next = node6;
	node7->next = node8;

	vector<ListNode*> lists;
	lists.push_back(node1);
	lists.push_back(node4);
	lists.push_back(node7);

	//ListNode* res = mergeKLists(lists);
	ListNode* res_v2 = mergeKlists_Ver2(lists);
	return;
}