class Solution {
public:
	double myPow(double x, int n) {
		//处理特殊值
		if (n == 0 || x == 1)
			return 1;
		//n小于0的次方
		if (n < 0)
			return (1 / (x*myPow(x, -n - 1)));
		//大于0
		//奇数
		if (n % 2 == 1)
			return x*myPow(x, n - 1);
		return myPow(x*x, n / 2);
	}
};