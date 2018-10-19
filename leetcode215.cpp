#include<vector>
using namespace std;
/*
�������򣺡�������ָ�뷨
1.ѡȡһ���ؼ���(key)��Ϊ���ᣬһ��ȡ�����¼�ĵ�һ����/���һ�����������ѡȡ�������һ����Ϊ���ᡣ
2.������������left = 0;right = N - 1;
3.��leftһֱ����ߣ�ֱ���ҵ�һ������key��ֵ��right�Ӻ���ǰ��ֱ���ҵ�һ��С��key��ֵ��Ȼ�󽻻�����������
4.�ظ���������һֱ�����ң�ֱ��left��right��������ʱ��key����left��λ�ü��ɡ�
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

	//�Ż���
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
	//���ÿ������򣬽����������ź��򷵻ص����ڶ���
	if (nums.size() <=0) {
		return 0;
	}

	QuickSort(nums,0,nums.size()-1);
	return nums[nums.size() - k];

}
//���ÿ�������˼�룬ÿ��ѡ��һ��ֵ��������߶�����С���ұ߶�������
//����պ��ǵ�n-k��λ�ã���Ϊ�������С��n-k���������ұ߼������ң���������߼������ҡ�
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