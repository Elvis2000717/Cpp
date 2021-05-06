class Solution {
public:
	int numWays(int n) {
		if (n == 0)
			return 1;
		int f1 = 1;
		int f2 = 2;
		if (n == 1)
			return f1;
		if (n == 2)
			return f2;
		int f3 = 0;
		for (int i = 1; i < n - 1; i++)
		{
			f3 = (f1 + f2) % 1000000007;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
};