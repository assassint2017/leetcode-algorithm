// 第一种思路，暴力回溯，果然超时了
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return dfs(nums, target, 0);
    }
private:
    int dfs(const vector<int>& nums, int target, int start)
    {
        if (start == nums.size() - 1)
        {
            int res = 0;
            
            target == nums.back() ? ++res : res;
            target == -nums.back() ? ++res : res;
            
            return res;
        }
        else
            return dfs(nums, target - nums[start], start + 1) + dfs(nums, target + nums[start], start + 1);
    }
};

// 第二种思路，使用动态规划
// Runtime: 44 ms, faster than 63.27% of C++ online submissions for Target Sum.
// Memory Usage: 21.1 MB, less than 30.77% of C++ online submissions for Target Sum.

class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum = 0;
        for (auto item : nums)
            sum += item;
        
        int maxValue = sum, minValue = -sum;
        
        // 边界条件处理
        if (nums.size() == 0 || S < minValue || S > maxValue)
            return 0;
        
        vector<vector<int>> dp(nums.size(), vector<int>(maxValue - minValue + 1, 0));
        
        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                if (i == 0)
                {
                    int temp = 0;
                    nums.back() == j + minValue ? ++temp : 0;
                    -nums.back() == j + minValue ? ++temp : 0;
                    dp[i][j] = temp;
                }
                else
                {
                    int index = nums.size() - i - 1;
                    if (j - nums[index] >= 0 && j - nums[index] < dp[0].size())
                        dp[i][j] += dp[i - 1][j - nums[index]];
                    if (j + nums[index] >= 0 && j + nums[index] < dp[0].size())
                        dp[i][j] += dp[i - 1][j + nums[index]];
                }
            }
        }
        return dp[dp.size() - 1][S - minValue];
    }
};