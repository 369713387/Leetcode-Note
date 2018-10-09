#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res;
	
	int row = n, col = n;
	int x = 0, y = 0;
	int ru = 0, rd = n, rl = 0, rr = n;
	int count = 1;
	bool finish = false;

	res.resize(n);
	for (int i = 0; i < n; i++) {
		res[i].resize(n);
	}
	while (true)
	{
		//1.向右遍历
		finish = false;
		while (x>=rl && x<rr)
		{
			res[y][x] = count++;
			x++;
			finish = true;
		}
		if (!finish) {
			break;
		}
		//2.向下遍历
		finish = false;
		x--;
		y++;
		ru++;
		while (y >= ru && y<rd)
		{
			res[y][x] = count++;
			y++;
			finish = true;
		}
		if (!finish) {
			break;
		}
		//3.向左遍历
		finish = false;
		x--;
		y--;
		rr--;
		while (x >= rl && x<rr)
		{
			res[y][x] = count++;
			x--;
			finish = true;
		}
		if (!finish) {
			break;
		}
		//4.向上遍历
		finish = false;
		x++;
		y--;
		rd--;
		while (y >= ru && y<rd)
		{
			res[y][x] = count++;
			y--;
			finish = true;
		}
		if (!finish) {
			break;
		}
		x++;
		y++;
		rl++;
	}

	return res;
}

void main() {
	vector<vector<int>> num;
	num = generateMatrix(3);
	return;
}