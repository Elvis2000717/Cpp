//class Solution {
//public:
//	int movingCount(int m, int n, int k) {
//		rows = m;
//		cols = n;
//		if (k < 9)
//		{
//			for (int i = 0; i < rows; i++)
//			{
//				for (int j = 0; j < cols; j++)
//				{
//					if (dns(i, j, k))
//						num += 1;
//					else
//						break;
//				}
//				if (change(i) > k)
//					break;
//			}
//		}
//		else
//		{
//			for (int i = 0; i < rows; i++)
//			{
//				for (int j = 0; j < cols; j++)
//				{
//					if (dns(i, j, k))
//						num += 1;
//				}
//			}
//		}
//		
//		return num;
//	}
//
//private:
//	int num = 0, rows, cols;
//	int change(int n)
//	{
//		int result = 0;
//		while (n)
//		{
//			result = result + (n % 10);
//			n = n / 10;
//		}
//		return result;
//	}
//	int dns(int row, int col, int k)
//	{
//		if (row >= rows || row < 0 || col >= cols || col < 0)
//			return 0;
//		if (change(row) + change(col) > k)
//			return 0;
//		return 1;
//	}
//};

class Solution {
	int change(int n)
	{
		int result = 0;
		while (n)
		{
			result = result + (n % 10);
			n = n / 10;
		}
		return result;
	}

public:
	int movingCount(int m, int n, int k)
	{
		if (k == 0)
			return 1;
		vector<vector<int> > vis(m, vector<int>(n, 0));
		int ans = 1;
		vis[0][0] = 1;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((i == 0 && j == 0) || change(i) + change(j) > k)
					continue;
				if (i - 1 >= 0)
					vis[i][j] |= vis[i - 1][j];
				if (j - 1 >= 0)
					vis[i][j] |= vis[i][j - 1];
				ans += vis[i][j];
			}
		}
		return ans;
	}
};

//class Solution {
//	int get(int x) {
//		int res = 0;
//		for (; x; x /= 10){
//			res += x % 10;
//		}
//		return res;
//	}
//public:
//	int movingCount(int m, int n, int k) {
//		if (!k) return 1;
//		vector<vector<int> > vis(m, vector<int>(n, 0));
//		int ans = 1;
//		vis[0][0] = 1;
//		for (int i = 0; i < m; ++i) {
//			for (int j = 0; j < n; ++j) {
//				if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;
//				// ±ß½çÅÐ¶Ï
//				if (i - 1 >= 0) vis[i][j] |= vis[i - 1][j];
//				if (j - 1 >= 0) vis[i][j] |= vis[i][j - 1];
//				ans += vis[i][j];
//			}
//		}
//		return ans;
//	}
//};
