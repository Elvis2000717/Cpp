#include <iostream>

using namespace std;

int findNumberOf1(int num)
{
	int n = 0;
	while (num)
	{
		if (num & 1 == 1)
			n++;
		num >>= 1;
	}
	return n;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int ret = findNumberOf1(n);
		cout << ret << endl;
	}
	return 0;
}