#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;//Êä³öµÄ×Ö·û´®
	string str2;//ÁÙÊ±×Ö·û´®
	string max;//×î³¤×Ö·û´®
	cin >> str1;
	
	for (int i = 0; i <= str1.size(); i++)
	{
		if ('0' <= str1[i] && str1[i] <= '9')
		{
			str2 += str1[i];
		}
		else
		{
			if (max.size() < str2.size())
			{
				max = str2;
			}
			str2.clear();
		}
	}
	cout << max << endl;

	return 0;
}