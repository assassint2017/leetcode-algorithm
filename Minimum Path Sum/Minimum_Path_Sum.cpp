// 典型的动态规划问题

// Runtime: 8 ms, faster than 98.39% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 11 MB, less than 43.01% of C++ online submissions for Minimum Path Sum.

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        // 边界条件处理
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        // 初始化一个二维的vector来保存结果
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        // 初始化边界，也就是第一行和第一列
        res[0][0] = grid[0][0];
        for (int i = 1; i < cols; i++)
            res[0][i] = grid[0][i] + res[0][i - 1];
        for (int i = 1; i < rows; i++)
            res[i][0] = grid[i][0] + res[i - 1][0];

        // 开始循环计算
        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++)
                res[i][j] = res[i - 1][j] < res[i][j - 1] ? grid[i][j] + res[i - 1][j] : grid[i][j] + res[i][j - 1];

        return res[rows - 1][cols - 1];        
    }
};