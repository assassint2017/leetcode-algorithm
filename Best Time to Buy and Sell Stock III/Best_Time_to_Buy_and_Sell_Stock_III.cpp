// 动态规划
// Runtime: 12 ms, faster than 15.16% of C++ online submissions for Best Time to Buy and Sell Stock III.
// Memory Usage: 5.7 MB, less than 2.29% of C++ online submissions for Best Time to Buy and Sell Stock III.

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() < 2)
            return 0;

        int *buy = new int[3], *sell = new int[3]();
        buy[0] = 0;
        buy[1] = -prices[0];
        buy[2] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 2; j >= 1; j--)
            {
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            }
        }
        int res = sell[2];

        delete[] sell;
        delete[] buy;

        return res;
    }
};