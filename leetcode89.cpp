#include<vector>
using namespace std;

vector<int> grayCode(int n) {
	int size = 1 << n;
	vector<int> res;
	for (int i = 0; i<size; i++) {
		int graycode = i ^ (i >> 1);
		res.push_back(graycode);
	}
	return res;
}

void main() {
	vector<int> res = grayCode(8);
	return;
}