#include <algorithm>
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;

		sort(nums.begin(), nums.end());
		int i = 0;
		while (i < nums.size() && nums[i] != target)
			i++;
		if (i >= nums.size())
			return 0;
		int j = i + 1;
		int total = 1;
		while (j < nums.size() && nums[i] == nums[j])
		{
			j++;
			total++;
		}
		return total;
	}
};