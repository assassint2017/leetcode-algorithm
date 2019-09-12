// 本质上依然是并查集的问题

// Runtime: 8 ms, faster than 78.17% of C++ online submissions for Redundant Connection.
// Memory Usage: 10.2 MB, less than 47.06% of C++ online submissions for Redundant Connection.

class Solution 
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int size = 0;
        for (auto &edge : edges)
        {
            size = max(size, edge[0]--);
            size = max(size, edge[1]--);
        }
        
        vector<int> uf(size, -1);
        vector<pair<int, int>> res;
        for (auto edge : edges)
        {
            if (union_(uf, edge[0], edge[1]))
            {
                res.push_back(pair<int, int>(edge[0], edge[1]));
            }
        }
        
        vector<int> finalres;
        finalres.push_back(res.back().first + 1);
        finalres.push_back(res.back().second + 1);
        return finalres;
    }
private:
    bool union_(vector<int>& uf, int index1, int index2)
    {
        int parent1 = find(uf, index1);
        int parent2 = find(uf, index2);
        
        if (parent1 == parent2)
            return true;
        else
        {
            if (uf[parent1] < uf[parent2])
            {
                uf[parent2] = parent1;
            }
            else
            {
                if (uf[parent1] == uf[parent2])
                    --uf[parent2];
                uf[parent1] = parent2;
            }
        }
        
        return false;
    }
    
    int find(vector<int>& uf, int index)
    {
        while (uf[index] >= 0)
            index = uf[index];
        return index;
    }
};