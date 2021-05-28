#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1;
	string str2;
	while (cin >> str1)
	{
		str2.insert(0, " ");
		str2.insert(0, str1);
	}
	cout << str2 << endl;

	return 0;
}