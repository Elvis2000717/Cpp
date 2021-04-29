#include <algorithm>
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		//���sizeС�ڵ���1���Ͳ������ظ�
		if (size <= 1)
		{
			return size;
		}

		//˳������
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