#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	
	while (str2.size())
	{
		for (int i = 0; i < str1.size(); i++)
		{
			if (str1[i] == str2[str2.size() - 1])
			{
				str1.erase(i, 1);
				i--;
			}
		}
		str2.pop_back();
	}
	cout << str1 << endl;

	return 0;
}