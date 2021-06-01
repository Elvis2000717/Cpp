#include <stdio.h>
#include <iostream>

using namespace std;

int lcm(int a, int b)
{
	if (a > b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int num = b;
	while (num % a != 0)
		num = num + b;
	return num;
}

int main()
{
	int a, b;
	cin >> a >> b;
	int ret = lcm(a, b);
	cout << ret << endl;

	return 0;
}