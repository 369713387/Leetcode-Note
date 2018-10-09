#include<iostream>
#include<vector>
using namespace std;

void dfsSearch(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
	if (i<0 || j<0 || i>rows || j>cols || grid[i][j] != '1') {
		return;
	}
	grid[i][j] = '2';
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << grid[i][j] << "  ";
		}
		cout << endl;
	}
	dfsSearch(grid, i - 1, j, rows, cols);
	dfsSearch(grid, i + 1, j, rows, cols);
	dfsSearch(grid, i, j + 1, rows, cols);
	dfsSearch(grid, i, j - 1, rows, cols);
}

int numIslands(vector<vector<char>>& grid) {
	int rows = grid.size();
	int cols = grid[0].size();
	if (rows == 0 || cols == 0) {
		return 0;
	}
	int count = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (grid[i][j] == '1') {
				count++;
				dfsSearch(grid, i, j, rows, cols);
			}
		}
	}
	return count;
}

void main() {
	const int rows = 4;
	const int cols = 5;
	vector<vector<char> > grid(rows, vector<char>(cols)); //二维数组的行数为4，列数为5。<int>后一定要加一个空格，否则会被判别为操作符>>出错
	char b[rows][cols] = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0' } };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			grid[i][j] = b[i][j];
			cout << grid[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
	numIslands(grid);
		
	return;
};