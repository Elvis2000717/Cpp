#include <iostream>
#include <vector>
using namespace std;

int Fibonacci(long num)
{
	if (num == 0 || num == 1)
		return 0;
	int f0 = 0;
	int f1 = 1;
	int f2 = 1;
	while (f2 < num)
	{
		f0 = f1;
		f2 = f1 + f2;
		f1 = f2 - f0;
	}
	int ret1 = f2 - num;
	if (ret1 < 0)
		ret1 = ret1*(-1);
	int ret2 = f1 - num;
	if (ret2 < 0)
		ret2 = ret2*(-1);
	if (ret1 > ret2)
		return ret2;
	return ret1;
}

int main()
{
	long n;
	cin >> n;
	int ret = Fibonacci(n);
	cout << ret << endl;
	return 0;
}