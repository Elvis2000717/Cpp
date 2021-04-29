#include <algorithm>
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		//如果size小于等于1，就不会有重复
		if (size <= 1)
		{
			return size;
		}

		//顺序排序
		sort(nums.begin(), nums.end());

		int p = 0;
		for (int i = 1; i < size; i++)
		{
			if (nums[p] != nums[i])
			{
				p++;
				nums[p] = nums[i];
			}
		}
		return p + 1;
	}
};