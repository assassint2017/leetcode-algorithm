// 典型的动态规划
// Runtime: 36 ms, faster than 88.91% of C++ online submissions for Coin Change.
// Memory Usage: 12.6 MB, less than 86.27% of C++ online submissions for Coin Change.
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> memo(amount + 1, 0);
        for (int i = 1; i <= amount; ++i)
        {
            int minValue = INT_MAX;
            bool found = false;
            for (int coin : coins)
            {
                if (i - coin < 0 || memo[i - coin] == -1)
                    continue;
                else
                {
                    minValue = min(minValue, memo[i - coin] + 1);    
                    found = true;    
                }        
            }
            memo[i] = found ? minValue : -1;
        }
        return memo[amount];
    }
};