class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int num = 0;
		int lmin = 27;//������Сֵ
		int rmin = 27;//������Сֵ
		int lsum = 0;//��������
		int rsum = 0;//��������
		for (int i = 0; i < n; i++)
		{
			if (right[i] == 0 || left[i] == 0)//ͳ��0�ĸ���
			{
				num = num + left[i] + right[i];
			}
			else
			{
				if (lmin > left[i])
				{
					lmin = left[i];//��Сֵ
				}
				if (rmin > right[i])
				{
					rmin = right[i];//��Сֵ
				}
				lsum = lsum + left[i];//zongshu
				rsum = rsum + right[i];//zongshu
			}
		}

		lsum = lsum - lmin;
		rsum = rsum - rmin;
		if (lsum < rsum)
		{
			num = num + lsum;
		}
		else
		{
			num = num + rsum;
		}
		num = num + 2;
		return num;
	}
};