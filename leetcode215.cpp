#include<vector>
using namespace std;
/*
快速排序：——左右指针法
1.选取一个关键字(key)作为枢轴，一般取整组记录的第一个数/最后一个，这里采用选取序列最后一个数为枢轴。
2.设置两个变量left = 0;right = N - 1;
3.从left一直向后走，直到找到一个大于key的值，right从后至前，直至找到一个小于key的值，然后交换这两个数。
4.重复第三步，一直往后找，直到left和right相遇，这时将key放置left的位置即可。
*/
int GetMid(vector<int> nums,int left,int right) {
	int mid = left + ((right - left) >> 1);
	if (nums[left] <= nums[right])
	{
		if (nums[mid] <  nums[left])
			return left;
		else if (nums[mid] > nums[right])
			return right;
		else
			return mid;
	}
	else
	{
		if (nums[mid] < nums[right])
			return right;
		else if (nums[mid] > nums[left])
			return left;
		else
			return mid;
	}
}

int GetPartion(vector<int>& nums, int left, int right, int k) {

	//优化版
	int mid = GetMid(nums, left, right);
	swap(nums[mid], nums[left]);
	k = nums[left];

	int len = nums.size();
	while (left<right)
	{
		while (nums[right] >= k && left<right) {
			right--;
		}
		swap(nums[left], nums[right]);

		while (nums[left]<=k && left<right) {
			left++;
		}
		swap(nums[left], nums[right]);
	}
	swap(nums[left], k);
	return left;
}

void QuickSort(vector<int>& nums, int left, int right) {
	if (left < right) {
		int partion = GetPartion(nums, left, right, nums[left]);
		QuickSort(nums, left, partion-1);
		QuickSort(nums, partion + 1, right);
	}	
}


int findKthLargest(vector<int>& nums, int k) {
	//利用快速排序，将整个数组排好序返回倒数第二个
	if (nums.size() <=0) {
		return 0;
	}

	QuickSort(nums,0,nums.size()-1);
	return nums[nums.size() - k];

}
//利用快速排序思想，每次选择一个值，让其左边都比他小，右边都比他大，
//如果刚好是第n-k的位置，即为所求。如果小于n-k，则在他右边继续查找，否则在左边继续查找。
int findKthLargest(vector<int>& nums, int k,int left,int right) {
	int tmp = nums[left], n = nums.size(), tleft = left, tright = right;
	while (left<right) {
		while (right>left&&nums[right]>tmp) right--;
		if (right>left) {
			nums[left++] = nums[right];
		}
		while (left<right&&nums[left] <= tmp) left++;
		if (left<right) nums[right--] = nums[left];
	}
	nums[left] = tmp;
	if (left == n - k) return tmp;
	else if (left<n - k) return findKthLargest(nums, k, left + 1, tright);
	else return findKthLargest(nums, k, tleft, left - 1);
}

void main() {
	vector<int> vec;
	vec.push_back(8);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(-2);
	vec.push_back(12);
	vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(5);
	vec2.push_back(7);
	vec2.push_back(-2);
	vec2.push_back(0);
	int res1 = findKthLargest(vec,2);
	int res2 = findKthLargest(vec2, 2, 0 ,vec2.size()-1);
	return;
}