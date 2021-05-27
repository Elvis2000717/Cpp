#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	int A, B, C;
	A = (a + c) / 2;
	B = (b + d) / 2;
	C = (d - B);
	if (A - B == a && B - C == b && A + B == c && B + C == d)
	{
		cout << A << " " << B << " " << C << endl;
		return 0;
	}
	cout << "No" << endl;

	return 0;
}