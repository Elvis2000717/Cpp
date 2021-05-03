#include <algorithm>
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
		{
			return{};
		}
		sort(nums.begin(), nums.end());

		int i = 0;
		int j = 1;

		while (j < nums.size())
		{
			if (nums[i] == nums[j])
			{
				return nums[i];
			}
			i++;
			j++;
		}
		return {};
	}
};