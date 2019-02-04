// 题目需要找到一个序列中（最小值，最大值）的pair
// Runtime: 4 ms, faster than 98.48% of C++ online submissions for Best Time to Buy and Sell Stock.// Memory Usage: 1.6 MB, less than 92.26% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = 0;
        int buyday = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            // 记录当前序列的最小值
            int sellday = prices[i];
            buyday = sellday < buyday ? sellday : buyday;
            
            int profit = sellday - buyday;
            res = profit > res ? profit : res;
        }
        return res;
    }
};