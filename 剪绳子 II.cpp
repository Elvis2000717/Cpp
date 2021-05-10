class Solution {
public:
	int cuttingRope(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		long long result = 1;
		while (n >= 5)
		{
			result = (result * 3) % 1000000007;
			n -= 3;
		}
		result = (result * n) % 1000000007;
		return result;
	}
};