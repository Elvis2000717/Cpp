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
		//n�ǵ�ǰ����ȼ���ĵڶ��ٸ�����
		n--;
		int target = n % count;//�ڼ���
		int group = n / count;//�ڶ��ٸ���

		sum = 1;
		int deng = count - 1;
		while (--count)
		{
			sum *= 10;
		}
		sum = sum + group;//sum�Ǿ��������
		int idx = deng - target;//���ֵ��±�
		while (idx)
		{
			idx--;
			sum /= 10;
		}
		sum %= 10;
		return sum;
	}
};