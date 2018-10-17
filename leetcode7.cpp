#include<iostream>
#include<limits.h>
using namespace std;

int reverse(int x) {
	long res = 0;
	if (x >= INT_MAX || x< INT_MIN) {
		return 0;
	}
	//1.先去掉末尾的0
	while (x && x % 10 == 0) {
		x /= 10;
	}
	//2.反转
	while (x)
	{
		res = res * 10 + x % 10;
		if (res < INT_MIN || res >= INT_MAX) {
			return 0;
		}
		x /= 10;
	}
	return res;
}

void main() {
	int x = reverse(2147483647);
	return;
}