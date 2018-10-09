#include<iostream>
#include<vector>
using namespace std;
/*
我们一次遍历的时候，得到顺序的乘积为ins，逆序的乘积为ret。
那么最后对于数组N中的除当前元素之外其余各元素的乘积，我们就可以利用ins和ret这两个数组来计算得到。
假设输出数组为output，对于output中的每一个元素，存在output [i] = ins [i-1] * ret [i+1]（注意边界条件）
*/
vector<int> productExceptSelf(vector<int>& nums) {
	int len = nums.size();
	vector<int> output(len,0);
	vector<int> ins(len, nums[0]);
	vector<int> ret(len, nums[len-1]);
	int tmpIns = nums[0], tmpRet = nums[len - 1];
	for (int i = 1; i < len; i++)
	{
		tmpIns *= nums[i];
		tmpRet *= nums[len - i -1];
		ins[i] = tmpIns;
		ret[len -i -1] = tmpRet;
	}
	//output [i] = ins [i-1] * ret [i+1]
	output[0] = ret[1];
	output[len-1] = ins[len - 2];
	for (int i = 1; i < len-1; i++)
	{
		output[i] = ins[i - 1] * ret[i + 1];
	}
	return output;

}



void main() {
	vector<int> res;
	for (int i = 0; i < 4; i++)
	{
		res.push_back(i+1);
	}
	res = productExceptSelf(res);
	return;
}