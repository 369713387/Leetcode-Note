#include<vector>
using namespace std;
/*
二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，
我们观察上面红色加粗的数字都是升序的，由此我们可以观察出规律，
如果中间的数小于最右边的数，则右半段是有序的，
若中间数大于最右边数，则左半段是有序的，
我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，
这样就可以确定保留哪半边了
*/
int search(vector<int>& nums, int target) {
	if (nums.size()<=0) {
		return -1;
	}

	int left = 0;
	int right = nums.size() - 1;
	
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		if (nums[mid] > nums[right]) {
			//左边有序
			if (target >= nums[left] && target < nums[mid]) {
				//在有序的半边
				right = mid - 1;
			}
			else
			{
				//在无序的半边
				left = mid + 1;
			}

		}
		else
		{
			//右边有序
			if (target > nums[mid] && target <= nums[right]) {
				//在有序的半边
				left = mid +1;
			}
			else
			{
				//在无序的半边
				right = mid - 1;
			}
		}
	}
	return -1;
}

void main() {
	vector<int> res;
	res.push_back(4);
	res.push_back(5);
	res.push_back(6);
	res.push_back(7);
	res.push_back(0);
	res.push_back(1);
	res.push_back(2);
	int r = search(res,0);
	return;
}