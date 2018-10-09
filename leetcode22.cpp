#include<iostream>
#include<string>
#include<vector>
using namespace std;

//回归条件： 如果左右括号都没了，那么把解返回解空间。
//选择条件1：如果左括号还有，那么就递归。
//递归关系： 如果左括号还有，那么就用掉一个左括号（字符串 + “（”，函数中left - 1）
//选择条件2：如果左括号剩余数量小于右括号剩余数量，那么就递归。
//递归关系： 用掉一个右括号

void backtrade(string substr,vector<string> &res,int left ,int right) {
	if (left <= 0 && right<=0) {
		res.push_back(substr);
		return;
	}
	
	if (left > 0) {
		backtrade(substr + "(", res, left - 1, right);
	}

	if (left<right)
	{
 		backtrade(substr + ")", res, left, right - 1);
	}
	
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	backtrade("", res, n, n);
	return res;
}



void main() {
	vector<string> res;
	int n;
	cin >> n;
	res = generateParenthesis(n);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "  ";
	}
	return;
}