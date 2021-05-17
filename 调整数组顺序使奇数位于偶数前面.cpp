class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return nums;

		int left = 0;
		int right = nums.size() - 1;
		while (left < right)
		{
			while (left < right && nums[left] % 2 == 1)
				left++;
			while (left < right && nums[right] % 2 == 0)
				right--;
			std::swap(nums[left], nums[right]);
		}
		return nums;
	}
};