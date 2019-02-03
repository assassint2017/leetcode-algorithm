// 经典的回溯算法
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-Queens II.
// Memory Usage: 753.7 KB, less than 94.74% of C++ online submissions for N-Queens II.

class Solution 
{
public:
    int totalNQueens(int n) 
    {
        vector<int> queens;
        int res = 0;
        
        dfs(n, queens, res);
        
        return res;
    }
private:
    void dfs(const int &col, vector<int> &queens, int &res)
    {
        for (int i = 0; i < col; i++)
        {
            if (isSafe(i, queens))
            {
                queens.push_back(i);

                // n个皇后都已经安排好
                if (queens.size() == col)
                    res++;
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
};


// 思路二 使用非递归的回溯
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-Queens II.
// Memory Usage: 757.8 KB, less than 87.72% of C++ online submissions for N-Queens II.

class Solution 
{
public:
    int totalNQueens(int n) 
    {
        if (n == 1) 
            return 1;

        vector<int> queens;
        int res = 0;

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
                        res++;
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
};