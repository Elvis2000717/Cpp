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
		board[row][col] = '\0';
		bool ret = dns(board, word, row + 1, col, n + 1) || dns(board, word, row - 1, col, n + 1) || dns(board, word, row, col - 1, n + 1) || dns(board, word, row, col + 1, n + 1);
		board[row][col] = word[n];
		return ret;
	}
};