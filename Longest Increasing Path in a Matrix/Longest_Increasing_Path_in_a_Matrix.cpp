// 解题思路是使用拓扑排序，想到这一点应该还是有点难度的

// Runtime: 100 ms, faster than 27.32% of C++ online submissions for Longest Increasing Path in a Matrix.
// Memory Usage: 27.8 MB, less than 24.84% of C++ online submissions for Longest Increasing Path in a Matrix.

class Solution 
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        // 边界条件处理
        int rows = matrix.size();
        if (rows == 0) return 0;

        int cols = matrix[0].size();
        if (cols == 0) return 0;

        vector<vector<int>> outadj(rows * cols);
        vector<int> degree(rows * cols, 0);

        // 统计每个节点的入度以及建立出邻接表
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int index = i * cols + j;

                // 与上方节点建立连接
                if (i - 1 >= 0)
                {
                    if (matrix[i][j] > matrix[i - 1][j]) ++degree[index];
                    if (matrix[i][j] < matrix[i - 1][j]) outadj[index].push_back(index - cols);
                }

                // 与下方节点建立连接
                if (i + 1 < rows)
                {
                    if (matrix[i][j] > matrix[i + 1][j]) ++degree[index];
                    if (matrix[i][j] < matrix[i + 1][j]) outadj[index].push_back(index + cols);
                }

                // 与左方节点建立连接
                if (j - 1 >= 0)
                {
                    if (matrix[i][j] > matrix[i][j - 1]) ++degree[index];
                    if (matrix[i][j] < matrix[i][j - 1]) outadj[index].push_back(index - 1);
                }

                // 与右方节点建立连接
                if (j + 1 < cols)
                {
                    if (matrix[i][j] > matrix[i][j + 1]) ++degree[index];
                    if (matrix[i][j] < matrix[i][j + 1]) outadj[index].push_back(index + 1);
                }
            }
        }
        
        queue<int> memo;
        int numOfLeft = rows * cols;
        
        // 首先纳入入度为0的节点
        for (int i = 0; i < rows * cols; ++i)
        {
            if (degree[i] == 0)
            {
                degree[i] = -1;
                --numOfLeft;
                memo.push(i);
            }
        }

        // 循环求解
        int res = 1;
        while (numOfLeft)
        {
            if (memo.empty()) break;

            ++res;
            for (int i = memo.size(); i > 0; --i)
            {
                int delNode = memo.front();
                memo.pop();

                for (auto item : outadj[delNode])
                {
                    if (--degree[item] == 0)
                    {
                        degree[item] = -1;
                        memo.push(item);
                        --numOfLeft;
                    }
                }
            }
        }
        return res;
    }
};