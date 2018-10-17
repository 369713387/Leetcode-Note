#include<iostream>
#include<vector>
#include<map>
using namespace std;
//����һ:��map
int majorityElement(vector<int>& nums) {

	if (nums.size() == 1) {
		return nums[0];
	}

	map<int, int> table;

	for (int i = 0; i < nums.size(); i++)
	{		
		if (table.count(nums[i])) {
			table[nums[i]]++;
			if (table[nums[i]] > nums.size() / 2) {
				return nums[i];
			}
		}
		else
		{
			table[nums[i]] = 1;
		}
	}
}
//������:��Ħ��ͶƱ��
//����ͶƱ���Ƚ���һ�����ּ���Ϊ������Ȼ��Ѽ�������Ϊ1���Ƚ���һ�����ʹ����Ƿ���ȣ�
//��������������һ����֮��һ��Ȼ�󿴴�ʱ��������ֵ����Ϊ�㣬����һ��ֵ��Ϊ��ѡ������
//�Դ�����ֱ���������������飬��ǰ��ѡ������Ϊ�������������
int majorityElement2(vector<int>& nums) {
	if (nums.size()==1) {
		return nums[0];
	}
	int count = 1;
	int res = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (count <= 0) {
			res = nums[i];
			count++;
		}
		else
		{
			if (nums[i] == res) {
				count++;
			}
			else
			{
				count--;
			}
		}			
	}
	return res;
	
}

void main() {
	vector<int> res;
	res.push_back(1);
	res.push_back(2);
	res.push_back(2);
	res.push_back(1);
	res.push_back(5);
	res.push_back(6);
	res.push_back(2);
	res.push_back(2);
	res.push_back(2);
	int val1 = majorityElement(res);
	int val2 = majorityElement2(res);
	return;
}