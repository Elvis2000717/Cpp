class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int ret = 0;//保存所有数的异或结果
		for (int n : nums)
			ret ^= n;
		int div = 1;//找异或结果最低位为1的位
		while ((div & ret) == 0)
			div <<= 1;
		int a = 0, b = 0;//保存两个单独的数字
		for (int n : nums)//将数组分为两组，根据div那一位是1还是0分组
		{
			if ((div & n) == 0)
				a ^= n;
			else
				b ^= n;
		}

		return vector<int>{a, b};
	}
};