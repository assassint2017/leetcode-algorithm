// 直接采用DFS来做
// memo 记录每个节点的状态
// 0 代表 not visited
// 1 代表 unsafe
// 2 代表 safe
// 3 代表 访问过了，但是目前还不清楚安全与否

// Runtime: 172 ms, faster than 62.12% of C++ online submissions for Find Eventual Safe States.
// Memory Usage: 31.7 MB, less than 100.00% of C++ online submissions for Find Eventual Safe States.

class Solution 
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& outadj) 
    {
        vector<int> res;
        int numOfNode = outadj.size();
        vector<int> memo(numOfNode, 0);
        
        
        for (int i = 0; i < numOfNode; ++i)
        {
            if (dfs(outadj, i, memo))
                res.push_back(i);
        }
        
        return res;
    }
private:
    bool dfs(vector<vector<int>>& outadj, int startNode, vector<int>& memo)
    {
        // 从备忘录中抽取结果
        if (memo[startNode] != 0)
        {
            if (memo[startNode] == 1)
                return false;
            else if (memo[startNode] == 2)
                return true;
            else
            {
                memo[startNode] = 1;
                return false;
            }
        }
        
        // dfs
        memo[startNode] = 3;
        for (int node : outadj[startNode])
        {
            if (dfs(outadj, node, memo) == false)
            {
                memo[startNode] = 1;
                return false;
            }
        }
        
        memo[startNode] = 2;
        return true;
    }
};