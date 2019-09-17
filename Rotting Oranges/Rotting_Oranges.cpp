// 基本思路是使用广度优先搜索进行加速
// Runtime: 4 ms, faster than 94.02% of C++ online submissions for Rotting Oranges.
// Memory Usage: 9.1 MB, less than 81.25% of C++ online submissions for Rotting Oranges.

class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // 边界条件处理
        int row = grid.size();
        if (row == 0) return -1;
        
        int col = grid[0].size();
        if (col == 0) return -1;
        
        // 首先纳入已经坏掉的橘子的坐标
        int numOfFresh = 0;
        int numOfRotten = 0;
        queue<pair<int, int>> poss;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++numOfFresh;
                }
                
                if (grid[i][j] == 2)
                {
                    ++numOfRotten;
                    poss.push(make_pair(i, j));
                }
            }
        }
        
        // 边界条件处理
        if (numOfFresh == 0 && numOfRotten == 0)
            return 0;
        if (numOfFresh == 0 && numOfRotten != 0)
            return 0;
        if (numOfFresh != 0 && numOfRotten == 0)
            return -1;
        
        // BFS
        int layer = 0;
        int offsetx[] = {-1, 1, 0, 0};
        int offsety[] = {0, 0, -1, 1};
        while (!poss.empty())
        {
            for (int i = poss.size(); i > 0; --i)
            {
                auto pos = poss.front();
                poss.pop(); 
                
                for (int j = 0; j < 4; ++j)
                {
                    int newx = pos.first + offsetx[j];
                    int newy = pos.second + offsety[j];
                    if (newx >= 0 && newx < row && newy >= 0 && newy < col && grid[newx][newy] == 1)
                    {
                        grid[newx][newy] = 2;
                        poss.push(make_pair(newx, newy));
                        
                        --numOfFresh;
                        ++numOfRotten;
                    }
                }
            }
            ++layer;
        }
        
        if (numOfFresh == 0)
            return layer - 1;
        else
            return -1;
    }
};