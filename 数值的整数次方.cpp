class Solution {
public:
	double myPow(double x, int n) {
		//��������ֵ
		if (n == 0 || x == 1)
			return 1;
		//nС��0�Ĵη�
		if (n < 0)
			return (1 / (x*myPow(x, -n - 1)));
		//����0
		//����
		if (n % 2 == 1)
			return x*myPow(x, n - 1);
		return myPow(x*x, n / 2);
	}
};