#include <iostream>
using namespace std;

int fun(int a, int b)
{
	if (a == 0 || b == 0)
		return 1;
	return fun(a - 1, b) + fun(a, b - 1);
}

int main()
{
	int n;//ºáÏò
	int m;//ÊúÏò
	while (cin >> n >> m)
		cout << fun(m, n) << endl;

	return 0;
}