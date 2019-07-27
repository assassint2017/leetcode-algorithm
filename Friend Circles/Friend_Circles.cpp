// 同样是典型的并查集

// Runtime: 16 ms, faster than 97.20% of C++ online submissions for Friend Circles.
// Memory Usage: 10.8 MB, less than 93.18% of C++ online submissions for Friend Circles.

class Solution 
{
public:
    int findCircleNum(vector<vector<int>>& matrix) 
    {
        // 边界条件处理
        int rows = matirx.size();
        if (rows == 0) return 0;

        int cols = matrix[0].size();
        if (cols == 0) return 0;
        
        // 初始化并查集
        vector<int> uf(cols, -1);

        // 构建并查集
        for (int i = 0; i < rows - 1; ++i)
            for (int j = i + 1; j < cols; ++j)
                if (matrix[i][j] == 1)
                    union_(uf, i, j);

        // 查询根节点的个数作为最终的返回结果
        int res = 0;
        for (int index = 0; index < uf.size(); ++index)
            if (uf[index] < 0)
                ++res;
        return res;
    }
private:
    void union_(vector<int>& uf, int pos1, int pos2)
    {
        int parent1 = find(uf, pos1);
        int parent2 = find(uf, pos2);

        if (parent1 != parent2)
        {
            int depth1 = -uf[parent1];
            int depth2 = -uf[parent2];

            if (depth1 < depth2)
                uf[parent1] = parent2;
            else
            {
                if (depth1 == depth2)
                    --uf[parent1];
                uf[parent2] = parent1;
            }
        }
    }

    int find(vector<int>& uf, int pos)
    {
        while (uf[pos] >= 0)
        {
            if (uf[uf[pos]] < 0) return uf[pos];
            pos = uf[pos] = uf[uf[pos]];
        }
        return pos;
    }
};