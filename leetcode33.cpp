#include<vector>
using namespace std;
/*
�����������Ĺؼ����ڻ�����м������ж�����Ҫ�������λ����Ұ�Σ�
���ǹ۲������ɫ�Ӵֵ����ֶ�������ģ��ɴ����ǿ��Թ۲�����ɣ�
����м����С�����ұߵ��������Ұ��������ģ�
���м����������ұ�����������������ģ�
����ֻҪ������İ��������β�����������ж�Ŀ��ֵ�Ƿ�����һ�����ڣ�
�����Ϳ���ȷ�������İ����
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
			//�������
			if (target >= nums[left] && target < nums[mid]) {
				//������İ��
				right = mid - 1;
			}
			else
			{
				//������İ��
				left = mid + 1;
			}

		}
		else
		{
			//�ұ�����
			if (target > nums[mid] && target <= nums[right]) {
				//������İ��
				left = mid +1;
			}
			else
			{
				//������İ��
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