#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		res = res ^ nums[i];
	}
	return res;
}

void main() {
	vector<int> res;
	res.push_back(1);
	res.push_back(2);
	res.push_back(1);
	res.push_back(2);
	res.push_back(4);
	res.push_back(3);
	res.push_back(4);
	int r = singleNumber(res);
	return;
}