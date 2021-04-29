class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;

		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; i++)
		{
			//每一行开辟上i列初值为0的空间
			vv[i - 1]. resize(i, 0);

			//每行的第一个元素为1
			vv[i - 1][0] = 1;

			//每行的最后一个元素为1
			vv[i - 1][i - 1] = 1;
		}

		//进入到行
		for (int i = 0; i < vv.size(); i++)
		{
			//进入到列
			for (int j = 0; j < vv[i].size(); j++)
			{
				//对初始化为0的值进行重新赋值
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;
	}
};