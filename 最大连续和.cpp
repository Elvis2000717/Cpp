#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> nums)
{
	int cur = nums[0];//记录当前值
	int max = nums[0];
	int prev = nums[0];     //记录前n-1个最大值

	for (int num : nums)
	{
		cur = num;
		if (prev > 0)
			cur = cur + prev;
		if (cur > max)
			max = cur;
		prev = cur;
	}
	return max;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	int val;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		nums.push_back(val);
	}

	int ret = maxSubArray(nums);
	cout << ret << endl;
	return 0;
}