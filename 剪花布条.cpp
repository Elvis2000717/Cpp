#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str, s;
	int num = 0;
	while (cin >> str >> s)
	{
		num = 0;
		size_t pos = 0;
		while ((pos = str.find(s, pos)) != string::npos)
		{
			pos += s.size();
			num++;
		}
		cout << num << endl;
	}

	return 0;
}