//#include <iostream>
//using namespace std;
class Solution {
public:
	int cuttingRope(int n) {
		if (n == 1 || n == 2)
			return 1;
		if (n == 3)
			return 2;
		int a = 0;
		int result = 1;

		if (n % 3 == 0)
		{
			a = n / 3;
			while (a--)
			{
				result *= 3;
			}
		}

		if (n % 3 == 1)
		{
			a = (n / 3) - 1;
			while (a)
			{
				result = 3 * result;
				a--;
			}
			result = result * 4;
		}

		if (n % 3 == 2)
		{
			a = n / 3;
			while (a)
			{
				result *= 3;
				a--;
			}
			result = result * 2;
		}
		return result;
	}
};

	//int main()
	//{
	//	int b = cuttingRope(10);
	//	cout << b << endl;

	//	return 0;
	//}