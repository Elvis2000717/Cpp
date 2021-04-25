#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> iv1;
	vector<int> iv2(5, 3);
	for (const auto &e : iv2)
		cout << e << " ";
	cout << endl;

	return 0;
}
void fun()
{
	vector<vector<int>> vv;
	vv.resize(5);

	for (int i = 0; i < 5; i++)
	{
		vv[i].resize(5);
	}
}