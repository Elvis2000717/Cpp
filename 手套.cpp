class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int num = 0;
		int lmin = 27;//左手最小值
		int rmin = 27;//右手最小值
		int lsum = 0;//左手总数
		int rsum = 0;//右手总数
		for (int i = 0; i < n; i++)
		{
			if (right[i] == 0 || left[i] == 0)//统计0的个数
			{
				num = num + left[i] + right[i];
			}
			else
			{
				if (lmin > left[i])
				{
					lmin = left[i];//最小值
				}
				if (rmin > right[i])
				{
					rmin = right[i];//最小值
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