#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		long long val = 0;
		vector<int> arr;
		arr.resize(3 * n);
		for (int i = 0; i < 3*n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());

		for (int i = 0; i < n; i++)
		{
			val = val + arr[arr.size() - (2 * (i + 1))];
		}
		cout << val << endl;
	}
	return 0;
}