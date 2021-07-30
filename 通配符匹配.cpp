#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int len1 = s.size();//m
		int len2 = p.size();//n

		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= len2; i++)//
		{
			if (p[i - 1] == '*')
			{
				dp[0][i] = 1;
			}
			else
			{
				break;
			}
		}

		for (int i = 1; i <= len1; i++)
		{
			if (s[i - 1] == '*')
			{
				dp[i][0] == 1;
			}
			else
			{
				break;
			}
		}

		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
				}
				else if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else{
					dp[i][j] = 0;
				}
			}
		}

		return dp[len1][len2];
	}
};

int main()
{
	string str1 = "aa";
	string str2 = "*";
	Solution a;
	int ret = a.isMatch(str1, str2);
	cout << ret << endl;


	return 0;
}