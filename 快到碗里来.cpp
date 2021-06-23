#include <iostream>
using namespace std;

int main()
{
	long long high;
	long long r;
	double p = 3.14;
	while (cin >> high >> r)
	{
		if (2 * p*r >= high)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	return 0;
}