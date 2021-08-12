#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool fun(int n)
{
	vector<int> arr;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			arr.push_back(i);
		}
	}
	int ret = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		ret += arr[i];
	}
	if (ret == n)
		return true;
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i < n; i++)
		{
			if (fun(i))
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}