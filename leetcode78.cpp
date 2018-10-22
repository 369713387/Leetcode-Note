#include<vector>
#include<algorithm>
using namespace std;

void backTrack(vector<vector<int>>& res, vector<int> subset, vector<int>& nums, const int& start) {
	/*res.push_back(subset);
	for (int i = start; i < nums.size(); i++)
	{
		subset.push_back(nums[i]);
		backTrack(res, subset, nums, i + 1);
		subset.pop_back();
	}*/
	if (start == (int)nums.size()) {
		res.push_back(subset);
		return;
	}
	backTrack(res, subset, nums, start + 1);
	subset.push_back(nums[start]);
	backTrack(res, subset, nums, start + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> subset;
	//sort(nums.begin(), nums.end());
	if (nums.empty()) { 
		res.push_back(subset);
		return res; 
	}
	backTrack(res, subset, nums, 0);
	return res;
}

void main() {
	vector<int> tmp = { 1,2,3,4,5,6,7,8,9,10 };
	vector<vector<int>> res = subsets(tmp);
	return;
}