class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int ret = 0;//�����������������
		for (int n : nums)
			ret ^= n;
		int div = 1;//����������λΪ1��λ
		while ((div & ret) == 0)
			div <<= 1;
		int a = 0, b = 0;//������������������
		for (int n : nums)//�������Ϊ���飬����div��һλ��1����0����
		{
			if ((div & n) == 0)
				a ^= n;
			else
				b ^= n;
		}

		return vector<int>{a, b};
	}
};