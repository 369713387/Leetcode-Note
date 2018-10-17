#include<iostream>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	if (x >= 0 && x <= 9) {
		return true;
	}
	long long res = 0;
	long long val = x;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	if (res == val) {
		return true;
	}
	return false;
}

void main() {
	bool flag = isPalindrome(2147483647);
	return;
}