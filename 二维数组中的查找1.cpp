class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int row = 0;
		int col = matrix[0].size() - 1;
		
		while (row <= matrix.size() - 1 && col >= 0)
		{
			if (target > matrix[row][col])
				row++;
			else if (target < matrix[row][col])
				col--;
			else
				return true;
		}
		return false;
	}
};