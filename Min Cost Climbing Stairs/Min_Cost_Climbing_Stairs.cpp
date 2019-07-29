// 动态规划

// Runtime: 12 ms, faster than 14.19% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 8.6 MB, less than 87.09% of C++ online submissions for Min Cost Climbing Stairs.

class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        if (cost.size() <= 1)
            return 0;
        
        vector<int> memo(cost.size());
        memo[0] = 0;
        memo[1] = min(cost[0], cost[1]);

        for (int i = 2; i < cost.size(); ++i)
        {
            memo[i] = min(memo[i - 1] + cost[i], memo[i - 2] + cost[i - 1]);
        }
        return memo.back();
    }
};