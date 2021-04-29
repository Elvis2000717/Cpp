class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;

		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; i++)
		{
			//ÿһ�п�����i�г�ֵΪ0�Ŀռ�
			vv[i - 1]. resize(i, 0);

			//ÿ�еĵ�һ��Ԫ��Ϊ1
			vv[i - 1][0] = 1;

			//ÿ�е����һ��Ԫ��Ϊ1
			vv[i - 1][i - 1] = 1;
		}

		//���뵽��
		for (int i = 0; i < vv.size(); i++)
		{
			//���뵽��
			for (int j = 0; j < vv[i].size(); j++)
			{
				//�Գ�ʼ��Ϊ0��ֵ�������¸�ֵ
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;
	}
};