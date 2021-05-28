#include <iostream>
#include <string>

using namespace std;

bool symmetry(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str1, str2, tmp;
	int count = 0, len;
	while (cin >> str1 >> str2)
	{
		len = str1.length();
		for (int i = 0; i < len + 1; i++)
		{
			tmp = str1;
			tmp.insert(i, str2);
			if (symmetry(tmp))
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}