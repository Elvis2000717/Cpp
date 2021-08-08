#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		//王炸最大
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else
		{
			int dash = line.find('-');
			//分成两个人的牌
			string str1 = line.substr(0, dash);
			string str2 = line.substr(dash + 1);

			//获取手牌数
			int c1 = count(str1.begin(), str1.end(), ' ');
			int c2 = count(str2.begin(), str2.end(), ' ');

			//取到第一牌
			string f1 = str1.substr(0, str1.find(' '));
			string f2 = str2.substr(0, str2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2)
			{
				//牌数一样，比第一张
				if (str.find(f1) > str.find(f2))
					cout << str1 << endl;
				else
					cout << str2 << endl;
			}
			else
			{
				//判断的是' '数量
				if (c1 == 3)
					cout << str1 << endl;
				else if (c2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}