class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		rows = board.size();
		cols = board[0].size();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (dns(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
private:
	int rows, cols;
	bool dns(vector<vector<char>>& board, string word, int row, int col, int n)
	{
		if (row >= rows || row < 0 || col >= cols || col < 0 || board[row][col] != word[n])
			return false;
		if (n == word.size() - 1)
			return true;
		char temp = board[row][col];
		board[row][col] = '\0';
		
		//Ñ­»·Êý×é
		int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
		for (int q = 0; q < 4; q++)
		{
			int m = row + dx[q], w = col + dy[q];
			if (dns(board, word, m, w, n + 1))
				return true;
		}

		board[row][col] = temp;
		return false;
	}
};