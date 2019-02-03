// 经典的回溯算法
// Runtime: 4 ms, faster than 78.16% of C++ online submissions for N-Queens.
// Memory Usage: 1.1 MB, less than 1.12% of C++ online submissions for N-Queens.

class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<int> queens;
        vector<vector<string>> res;
        
        dfs(n, queens, res);
        
        return res;
    }
private:
    void dfs(const int &col, vector<int> &queens, vector<vector<string>> &res)
    {
        for (int i = 0; i < col; i++)
        {
            if (isSafe(i, queens))
            {
                queens.push_back(i);

                // n个皇后都已经安排好
                if (queens.size() == col)
                    res.push_back(genBoard(queens));
                else
                    dfs(col, queens, res);
                queens.pop_back();
            }
        }
    }

    // 给定一个坐标，判断在该点落子是否安全
    bool isSafe(int curCol, vector<int> &queens)
    {
        int curRow = queens.size();
        for (int i = 0; i < queens.size(); i++)
        {
            // 计算当前皇后的坐标点
            int queenRow = i;
            int queenCol = queens[i];

            // 如果列号相同，则直接退出循环
            if (curCol == queenCol)
                return false;
            
            // 如果位于对角线上，也直接返回
            if ((curRow - queenRow) == (curCol - queenCol) || (curRow - queenRow) == (queenCol - curCol))
                return false;
        }
        return true;
    }

    // 根据n位皇后的坐标生成棋盘
    vector<string> genBoard(vector<int> &queens)
    {
        vector<string> board;
        for (auto queen : queens)
        {
            string temp(queens.size(), '.');
            temp[queen] = 'Q';
            board.push_back(temp);
        }
        return board;
    }
};

// 思路二 使用非递归的回溯
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-Queens.
// Memory Usage: 1.1 MB, less than 1.12% of C++ online submissions for N-Queens.

class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {   
        vector<int> queens;
        vector<vector<string>> res;

        if (n == 1)
        {
            vector<string> temp(1, "Q");
            res.push_back(temp);
            return res;
        }

        int i = 0, j = 0;
        while (true)
        {
            bool found = false;
            for (; j < n; j++)
            {
                if (isSafe(j, queens))
                {
                    found = true;
                    queens.push_back(j);
                    if (queens.size() == n)
                    {
                        res.push_back(genBoard(queens));
                        queens.pop_back();
                        found = false;
                    }
                    else
                        break;
                }
            }
            if (found) 
            {
                i++;
                j = 0;
            }
            else
            {
                i--;
                j = queens.back() + 1;
                queens.pop_back();

                if (i == 0 && j == n) return res;
            }
        }
    }

private:
    // 给定一个坐标，判断在该点落子是否安全
    bool isSafe(int curCol, vector<int> &queens)
    {
        int curRow = queens.size();
        for (int i = 0; i < queens.size(); i++)
        {
            // 计算当前皇后的坐标点
            int queenRow = i;
            int queenCol = queens[i];

            // 如果列号相同，则直接退出循环
            if (curCol == queenCol)
                return false;
            
            // 如果位于对角线上，也直接返回
            if ((curRow - queenRow) == (curCol - queenCol) || (curRow - queenRow) == (queenCol - curCol))
                return false;
        }
        return true;
    }

    // 根据n位皇后的坐标生成棋盘
    vector<string> genBoard(vector<int> &queens)
    {
        vector<string> board;
        for (auto queen : queens)
        {
            string temp(queens.size(), '.');
            temp[queen] = 'Q';
            board.push_back(temp);
        }
        return board;
    }
};