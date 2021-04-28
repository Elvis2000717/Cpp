//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		vector<int>::iterator it = nums.begin();
//		int value = 0;
//		int i = 0;
//		while (it != nums.end())
//		{
//			value ^= nums[i];
//			it++;
//			i++;
//		}
//		return value;
//	}
//};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = nums[0];
		if (nums.size() <= 1)
		{
			return value;
		}

		for (int i = 1; i < nums.size(); i++)
		{
			value ^= nums[i];
		}
		return value;
	}
};