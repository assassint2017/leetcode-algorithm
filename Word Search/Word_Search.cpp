// 典型的回溯
// Runtime: 28 ms, faster than 75.07% of C++ online submissions for Word Search.
// Memory Usage: 12.5 MB, less than 52.94% of C++ online submissions for Word Search.

class Solution
{
public:
	bool exist(vector<vector<char>>& matrix, string word)
	{
		// 边界条件处理
		if (word.size() == 0) return false;

		int row = matrix.size();
		if (row == 0) return false;

		int col = matrix[0].size();
		if (col == 0) return false;

		// 循环查找
		vector<vector<bool>> visited(row, vector<bool>(col, false));
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (matrix[i][j] == word[0])
				{
					visited[i][j] = true;

					if (dfs(matrix, word, visited, i, j, 1))
						return true;

					visited[i][j] = false;
				}
			}
		}
		return false;
	}
private:
	bool dfs(const vector<vector<char>>& matrix, const string& word, vector<vector<bool>>& visited, int starti, int startj, int start)
	{
		if (start == word.length())
			return true;
		else
		{
			// 向上寻找
			if (starti - 1 >= 0 && !visited[starti - 1][startj] && matrix[starti - 1][startj] == word[start])
			{
				visited[starti - 1][startj] = true;
				if (dfs(matrix, word, visited, starti - 1, startj, start + 1))
					return true;
				visited[starti - 1][startj] = false;
			}

			// 向下寻找
			if (starti + 1 < matrix.size() && !visited[starti + 1][startj] && matrix[starti + 1][startj] == word[start])
			{
				visited[starti + 1][startj] = true;
				if (dfs(matrix, word, visited, starti + 1, startj, start + 1))
					return true;
				visited[starti + 1][startj] = false;
			}

			// 向左寻找
			if (startj - 1 >= 0 && !visited[starti][startj - 1] && matrix[starti][startj - 1] == word[start])
			{
				visited[starti][startj - 1] = true;
				if (dfs(matrix, word, visited, starti, startj - 1, start + 1))
					return true;
				visited[starti][startj - 1] = false;
			}

			// 向右寻找
			if (startj + 1 < matrix[0].size() && !visited[starti][startj + 1] && matrix[starti][startj + 1] == word[start])
			{
				visited[starti][startj + 1] = true;
				if (dfs(matrix, word, visited, starti, startj + 1, start + 1))
					return true;
				visited[starti][startj + 1] = false;
			}

			return false;
		}
	}
};