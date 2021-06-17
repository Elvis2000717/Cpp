#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dir(string str1, string str2)//1大 2小
{
	int strlen1 = str1.length();
	int strlen2 = str2.length();
	int i = 0;
	while (str1[i] == str2[i])
	{
		if (i + 1 < strlen1 && i + 1 < strlen2)
			i++;
		else if (i + 1 < strlen1)//2不够
			return true;
		else if (i + 1 < strlen2)//1不够
			return false;
		else
			return true;
	}
	if (str1[i] < str2[i])
		return false;
	return true;
}

bool Lex(vector<string> str)
{
	int n = str.size();
	for (int i = 1; i < str.size(); i++)
	{
		if (!dir(str[i], str[i - 1]))
			return false;
	}
	return true;
}

bool Len(vector<string> str)
{
	int n = str.size();
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i - 1].length() > str[i].length())
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	string str;
	vector<string> a;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		a.push_back(str);
	}
	if (Lex(a) && Len(a))
		cout << "both" << endl;
	else if (Lex(a))
		cout << "lexicographically" << endl;
	else if (Len(a))
		cout << "lengths" << endl;
	else
		cout << "none" << endl;

	return 0;
}