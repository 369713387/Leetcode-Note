#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> split(string s,string pattern) {
	vector<string> res;
	string::size_type pos;
	s += pattern;
	for (int i = 0; i < s.size(); i++)
	{
		pos = s.find(pattern, i);
		if (pos < s.size()) {
			string tmp = s.substr(i, pos - i);
			res.push_back(tmp);
			i = pos + pattern.size() - 1;
		}
	}
	return res;
}

string reverseWords(string s) {
	string reverseStr;
	vector<string> splitStr = split(s, " ");
	for (int i = 0; i < splitStr.size(); i++)
	{
		reverse(splitStr[i].begin(), splitStr[i].end());
		reverseStr += splitStr[i];
		if (i != splitStr.size() - 1) {
			reverseStr += " ";
		}
	}
	return reverseStr;
}

void main() {
	cout << reverseWords("Let's take LeetCode contest");
	return;
}