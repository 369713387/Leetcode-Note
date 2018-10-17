#include<iostream>
#include<vector>
#include<map>
using namespace std;
//方法一:用map
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
//方法二:用摩尔投票法
//这种投票法先将第一个数字假设为众数，然后把计数器设为1，比较下一个数和此数是否相等，
//若相等则计数器加一，反之减一。然后看此时计数器的值，若为零，则将下一个值设为候选众数。
//以此类推直到遍历完整个数组，当前候选众数即为该数组的众数。
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