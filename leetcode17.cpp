#include<iostream>
#include<string>
#include<vector>
using namespace std;

void letterCombinations(string &digits, string &str, int index, vector<string> &result) {
	if (index == digits.size()) {
		result.push_back(str);
		return;
	}
	string base[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	for (int i = 0; i < base[digits[index] - '0'].size(); i++) {
		str += base[digits[index] - '0'][i];
		letterCombinations(digits, str, index + 1, result);
		str.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	// write your code here
	if (digits.size() <= 0) {
		return vector<string>();
	}
	vector<string> result;
	string str;
	letterCombinations(digits, str, 0, result);
	return result;
}

void main() {
	vector<string> res;
	res = letterCombinations("23");
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "  ";
	}
	return;
}