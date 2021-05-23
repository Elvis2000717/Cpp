class Solution {
public:
	int findNthDigit(int n) {
		if (n < 10)
		{
			return n;
		}
		int count = 1;
		long sum = 9;
		while (n >= sum)
		{
			n = n - sum;
			sum = (sum / count) * 10 * (count + 1);
			count++;
		}
		//n是当前这个等级里的第多少个数字
		n--;
		int target = n % count;//第几个
		int group = n / count;//第多少个组

		sum = 1;
		int deng = count - 1;
		while (--count)
		{
			sum *= 10;
		}
		sum = sum + group;//sum是具体的数字
		int idx = deng - target;//数字的下标
		while (idx)
		{
			idx--;
			sum /= 10;
		}
		sum %= 10;
		return sum;
	}
};