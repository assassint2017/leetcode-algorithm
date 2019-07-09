// 典型的union find

// Runtime: 12 ms, faster than 94.96% of C++ online submissions for Number of Islands.
// Memory Usage: 11.1 MB, less than 38.52% of C++ online submissions for Number of Islands.

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        // 边界条件处理
        int rows = grid.size();
        
        if (rows == 0)
        {
            return 0;
        }
        
        int cols = grid[0].size();
        
        if (cols == 0)
        {
            return 0;
        }

        // 初始化并查集
        // depth parent
        vector<pair<int, int>> unionTree(rows * cols);

        for (int index = 0 ; index < unionTree.size(); index++)
        {
            unionTree[index].first = 1;
            unionTree[index].second = index;
        }

        // 构建并查集
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    int index1 = i * cols + j;

                    // 和上边的陆地进行合并
                    if (i - 1 >= 0 && grid[i - 1][j] == '1')
                    {    
                        int index2 = (i - 1) * cols + j;
                        unionx(index1, index2, unionTree);
                    }

                    // 和左边的陆地进行合并
                    if (j - 1 >= 0  && grid[i][j - 1] == '1')
                    {
                        int index2 = i * cols + (j - 1);
                        unionx(index1, index2, unionTree);
                    }
                }
            }
        }

        // 遍历查找孤岛的数量
        int res = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    if (unionTree[i * cols + j].second == i * cols + j)
                    {
                        res++;
                    }
                }
            }
        }

        return res;
    }
private:

    // 所能接受的最大查询路径长度
    int maxPathLength = 3;

    void unionx(int index1, int index2, vector<pair<int, int>>& unionTree)
    {
        int parent1 = findParent(index1, unionTree);
        int parent2 = findParent(index2, unionTree);

        if (parent1 == parent2)
        {
            return ;
        }

        // 将高度较低的树向高度较高的树进行合并
        if (unionTree[parent1].first > unionTree[parent2].first)
        {
            unionTree[parent2].second = parent1;
        }
        else
        {
            unionTree[parent1].second = parent2;

            if (unionTree[parent1].first == unionTree[parent2].first)
            {
                unionTree[parent2].first++;
            }
        }
    }

    // 如果需要进一步加速就要使用路径压缩算法
    int findParent(int index, vector<pair<int, int>>& unionTree)
    {
        int initIndex = index;
        int pathLength = 0;

        while (unionTree[index].second != index)
        {
            pathLength++;
            index = unionTree[index].second;
        }

        if (pathLength > maxPathLength)
        {
            while (initIndex != index)
            {
                int temp = initIndex;
                initIndex = unionTree[initIndex].second;
                unionTree[temp].second = index;
            }
        }

        return index;
    }
};