#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
	vector<int> res;
	int row = matrix.size();
	int col = row ? matrix[0].size() : 0;
	if (!row || !col) return res;
	int x = 0, y = 0;
	int ru = 0, rd = row, rl = 0, rr = col;
	bool finish = false;
	while (true)
	{
		//1.向左遍历
		finish = false;
		while (y>=rl && y<rr)
		{
			res.push_back(matrix[x][y]);
			y++;
			finish = true;
		}
		if (!finish) break;
		//2.向下遍历
		finish = false;
		y--;
		x++;
		ru++;
		while (x >= ru && x<rd)
		{
			res.push_back(matrix[x][y]);
			x++;
			finish = true;
		}
		if (!finish) break;
		//3.向左遍历
		finish = false;
		y--;
		x--;
		rr--;
		while (y >= rl && y<rr)
		{
			res.push_back(matrix[x][y]);
			y--;
			finish = true;
		}
		if (!finish) break;
		//4.向上遍历
		finish = false;
		y++;
		x--;
		rd--;
		while (x >= ru && x<rd)
		{
			res.push_back(matrix[x][y]);
			x--;
			finish = true;
		}
		if (!finish) break;
		x++; y++; rl++;
	}
	return res;
}


void main() {
	vector<vector<int>> num;
	vector<int> res;
	int count = 0;
	num.resize(5);
	for (int i = 0; i < 5; i++) {
		num[i].resize(5);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			num[i][j] = count++;
		}
	}
	res = spiralOrder(num);
	return;
}