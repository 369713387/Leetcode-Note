#include<vector>
#include<iostream>
using namespace std;

void backTrack(vector<vector<int>> &res, vector<int> &tmp, const vector<int>& nums) {
	vector<int>::iterator tar;
	if (tmp.size() == nums.size()) {
		res.push_back(tmp);
	}
	else {
		for (int i = 0; i<nums.size(); ++i) {
			tar = find(tmp.begin(), tmp.end(), nums[i]);
			if (tar != tmp.end()) {
				cout << i << endl;
				continue;
			}
			tmp.push_back(nums[i]);			
			backTrack(res, tmp, nums);
			tmp.pop_back();
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> tmp;
	backTrack(res, tmp, nums);
	return res;
}

void main() {

	
	vector<int> nums = {1,2,3};
	vector<vector<int>> res = permute(nums);
	return;
}