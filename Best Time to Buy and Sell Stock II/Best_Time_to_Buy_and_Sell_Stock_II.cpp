// 累计每一个递增序列
// Runtime: 4 ms, faster than 99.43% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 1.6 MB, less than 93.04% of C++ online submissions for Best Time to Buy and Sell Stock II.

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                res += (prices[i] - prices[i - 1]);
        }
        return res;
    }
};