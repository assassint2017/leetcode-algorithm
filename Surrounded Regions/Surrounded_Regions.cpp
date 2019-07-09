// 解题思路依然使用并查集，特殊点在于使用了一个虚拟的父亲节点将所有边界上、以及边界上的邻居点都串起来了
// 对于路径压缩，另外一种方法是https://leetcode.com/problems/surrounded-regions/discuss/41617/Solve-it-using-Union-Find，对路径长度减半

// Runtime: 24 ms, faster than 98.26% of C++ online submissions for Surrounded Regions.
// Memory Usage: 14.4 MB, less than 34.94% of C++ online submissions for Surrounded Regions.

class Solution 
{
public:
    void solve(vector<vector<char>>& board) 
    {
        // 边界条件处理
        rows = board.size();
        
        if (rows == 0)
        {
            return ;
        }
        
        cols = board[0].size();
        
        if (cols == 0)
        {
            return ;
        }
        
        // 构建并查集
        vector<pair<int, int>> unionTree(rows * cols + 1);
        
        // 初始化并查集 depth parent
        for (int i = 0; i < unionTree.size(); i++)
        {
            unionTree[i].first = 1;
            unionTree[i].second = i;
        }
        
        // 构建并查集
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O')
                {
                    int index1 = i * cols + j;
                    
                    // 如果目标在边界上，将其和一个dummy node连接在一起
                    if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
                    {
                        int index2 = rows * cols;
                        unionx(index1, index2, unionTree);
                    }
        
                    // 和上边的数据相连
                    if (i - 1 >= 0 && board[i - 1][j] == 'O')
                    {    
                        int index2 = (i - 1) * cols + j;
                        unionx(index1, index2, unionTree);
                    }
                    
                    // 和左边的数据相连
                    if (j - 1 >= 0 && board[i][j - 1] == 'O')
                    {
                        int index2 = i * cols + (j - 1);
                        unionx(index1, index2, unionTree);
                    }
                    
                }
            }
        }
        
        // 根据构建好的并查集来翻转数据
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O')
                {
                    if (findParent(i * cols + j, unionTree) != findParent(rows * cols, unionTree))
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
    
private:
    
    // 所能接受的最大查询路径长度
    int maxPathLength = 3;
    int rows;
    int cols;
    
    // 合并函数
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
    
    // 查找父亲节点
    // 如果需要进一步加速就要使用路径压缩算法
    int findParent(int index, vector<pair<int, int>>& unionTree)
    {
        int initIndex = index;
        int pathLength = 0;

        while (unionTree[index].second != index && unionTree[index].second != -1)
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
