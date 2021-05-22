#include <algorithm>
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int len = nums.size();
		if (len < 4)
		{
			return nums[0];
		}
		sort(nums.begin(), nums.end());

		int first = nums[0];
		int second = nums[1];
		int i = 0;

		while (first == second)
		{
			if (i + 4 >= len)
			{
				return nums[i + 3];
			}
			i += 3;
			first = nums[i];
			second = nums[i + 1];
		}
		return first;
	}
};