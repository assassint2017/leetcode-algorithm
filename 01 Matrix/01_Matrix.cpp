// 第一种思路 暴力BFS 超时了

class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        // 边界条件处理
        rows = matrix.size();
        if (rows == 0) return vector<vector<int>>();

        cols = matrix[0].size();
        if (cols == 0) return vector<vector<int>>();

        // 初始化
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        // 迭代求解
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (matrix[i][j] == 1)
                    res[i][j] = helper(matrix, i, j);

        return res;
    }
private:
    int rows, cols;
private:
    int helper(vector<vector<int>>& matrix, int i, int j)
    {
        queue<pair<int, int>> memo;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        memo.push(pair<int, int>(i, j));
        visited[i][j] = true;

        int distance = 0;
        while (!memo.empty())
        {
            ++distance;
            for (int i = memo.size(); i > 0; --i)
            {
                auto pos = memo.front();
                memo.pop();

                if (pos.first - 1 >= 0 && !visited[pos.first - 1][pos.second])
                {
                    if (matrix[pos.first - 1][pos.second] == 0)
                        return distance;
                    else
                    {
                        memo.push(pair<int, int>(pos.first - 1, pos.second));
                        visited[pos.first - 1][pos.second] = true;
                    }
                }
                
                if (pos.first + 1 < rows && !visited[pos.first + 1][pos.second])
                {
                    if (matrix[pos.first + 1][pos.second] == 0)
                        return distance;
                    else
                    {
                        memo.push(pair<int, int>(pos.first + 1, pos.second));
                        visited[pos.first + 1][pos.second] = true;
                    }
                }

                if (pos.second - 1 >= 0 && !visited[pos.first][pos.second - 1])
                {
                    if (matrix[pos.first][pos.second - 1] == 0)
                        return distance;
                    else
                    {
                        memo.push(pair<int, int>(pos.first, pos.second - 1));
                        visited[pos.first][pos.second - 1] = true;
                    }
                }

                if (pos.second + 1 < cols && !visited[pos.first][pos.second + 1])
                {
                    if (matrix[pos.first][pos.second + 1] == 0)
                        return distance;
                    else
                    {
                        memo.push(pair<int, int>(pos.first, pos.second + 1));
                        visited[pos.first][pos.second + 1] = true;
                    }
                }
            }
        }
        return -1;
    }
};


// 第二种思路，高效版的BFS
class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
         // 边界条件处理
        int rows = matrix.size();
        if (rows == 0) return vector<vector<int>>();

        int cols = matrix[0].size();
        if (cols == 0) return vector<vector<int>>();   

        // 初始化
        vector<vector<int>> res(rows, vector<int>(cols));

        int maxdis = rows + cols;
        
        // 迭代求解
        queue<pair<int, int>> memo;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == 1)
                    res[i][j] = maxdis;
                else
                    memo.push(make_pair(i, j));
            }
        }
        
        // 上下左右四个偏移量
        int offseti[] = {-1, 1, 0, 0};
        int offsetj[] = {0, 0, -1, 1};
        while (!memo.empty())
        {
            auto pos = memo.front();
            memo.pop();
            
            for (int i = 0; i < 4; ++i)
            {
                int x = pos.first + offseti[i];
                int y = pos.second + offsetj[i];

                if (x >= 0 && x < rows && y >= 0 && y < cols)
                {
                    if (res[x][y] == maxdis)
                        memo.push(make_pair(x, y));

                    res[x][y] = min(res[x][y], res[pos.first][pos.second] + 1);
                }
            }
        }
        return res;
    }
};

// 对于第二种解法，也可以这样写
class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
         // 边界条件处理
        int rows = matrix.size();
        if (rows == 0) return vector<vector<int>>();

        int cols = matrix[0].size();
        if (cols == 0) return vector<vector<int>>();   

        // 初始化
        vector<vector<int>> res(rows, vector<int>(cols));

        int maxdis = rows + cols;
        
        // 迭代求解
        queue<pair<int, int>> memo;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == 1)
                    res[i][j] = maxdis;
                else
                    memo.push(make_pair(i, j));
            }
        }
        
        // 上下左右四个偏移量
        int offseti[] = {-1, 1, 0, 0};
        int offsetj[] = {0, 0, -1, 1};
        
        int layer = 0;
        while (!memo.empty())
        {
            layer++;
            for (int i = memo.size(); i > 0; i--)
            {
                auto pos = memo.front();
                memo.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int x = pos.first + offseti[i];
                    int y = pos.second + offsetj[i];

                    if (x >= 0 && x < rows && y >= 0 && y < cols)
                    {
                        if (res[x][y] == maxdis)
                            memo.push(make_pair(x, y));

                        if (matrix[x][y] == 1) res[x][y] = min(res[x][y],  layer);
                    }
                }
            }
        }
        return res;
    }
};
