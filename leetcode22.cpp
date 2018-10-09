#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�ع������� ����������Ŷ�û�ˣ���ô�ѽⷵ�ؽ�ռ䡣
//ѡ������1����������Ż��У���ô�͵ݹ顣
//�ݹ��ϵ�� ��������Ż��У���ô���õ�һ�������ţ��ַ��� + ��������������left - 1��
//ѡ������2�����������ʣ������С��������ʣ����������ô�͵ݹ顣
//�ݹ��ϵ�� �õ�һ��������

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