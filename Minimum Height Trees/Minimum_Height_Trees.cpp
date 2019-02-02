// 从任意一个点出发，计算距离最大的点，然后从这个点出发，再次计算距离最大的点
// 两个点的中点（可能有两个）就是树根，即使存在多个最长路径，他们的中点也是共享的
// 还可以使用拓扑排序 一层一层的删除节点，最后的一个或者两个就是根节点
// 下面的代码就是利用了拓扑排序

// Runtime: 24 ms, faster than 99.29% of C++ online submissions for Minimum Height Trees.
// Memory Usage: 2.6 MB, less than 100.00% of C++ online submissions for Minimum Height Trees.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
    {
        // 建立邻接表
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }

        // 初始化图中每一个节点的度
        vector<int> degree(n);
        for (int i = 0; i < n; i++)
            degree[i] = adj[i].size();
            
        // 拓扑排序
        int leftNode = n;
        queue<int> delNode;

        if (leftNode > 2)
        {
            // 首先收录第一层节点
            for (int i = 0; i < n; i++)
            {
                if (degree[i] == 1)
                {
                    degree[i] = -1;
                    leftNode--;
                    delNode.push(i);
                }
            }
        }

        while (leftNode > 2)
        {
            // 更新剩余节点的度
            int size = delNode.size();
            for (int i = 0; i < size; i++)
            {
                int node = delNode.front();
                delNode.pop();

                for (auto item : adj[node])
                {
                    if (--degree[item] == 1)
                    {
                        delNode.push(item);
                        degree[item] = -1;
                        leftNode--;
                    }
                }
            }
        }

        // 返回当前节点度大于等于0的节点
        vector<int> roots;
        for (int i = 0; i < n; i++)
            if (degree[i] >= 0)
                roots.push_back(i);
        return roots;
    }
};