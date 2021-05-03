class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		//ÂùÁ¦·¨
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return false;
		}
		int rows = matrix.size(), columns = matrix[0].size();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (matrix[i][j] == target)
				{
					return true;
				}
			}
		}
		return false;
	}
};