class Solution {
public:
	int missingNumber(vector<int>& nums) {
		if (nums.size() == 0)
			return{};
		int i;
		for (i = 0; i < nums.size(); i++)
		{
			if (i != nums[i])
			{
				return i;
			}
		}
		return i;
	}
};