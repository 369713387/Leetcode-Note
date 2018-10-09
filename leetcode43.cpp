#include<iostream>
#include<vector>
#include<string>
using namespace std;

string multiply(string s1,string s2) {
	if (s1 == "0" || s2 == "0") {
		return "0";
	}
	int len1 = s1.size(), len2 = s2.size();
	int n = len1 + len2;
	//两数相乘结果位数最多为len1+len2
	vector<int> res(n, 0);
	int k = n - 2;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			//从高位开始运算
			res[k - i - j] += (s1[i] - '0')*(s2[j] - '0');
		}
		int carry = 0;
		for (int i = 0; i < n; i++) {
			//从低位开始进位
			res[i] += carry;
			carry = res[i] / 10;
			res[i] %= 10;
		}
		//消除高位的0
		int t = n - 1;
		while (res[t] == 0) {
			--t;
		}
		string result;
		while (t >= 0) {
			result.append(1, res[t] + '0');
			--t;
		}
		return result;
	}
}

void main() {
	cout<<multiply("123", "456");
	return;
}