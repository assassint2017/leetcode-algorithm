// 动态规划
// Runtime: 112 ms, faster than 44.11% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
// Memory Usage: 11.8 MB, less than 0.99% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        if (prices.size() <= 1)
            return 0;

        int ownLast = -prices[0];
        int notownLast = 0;

        int own, notown;
        for (auto price : prices)
        {
            own = max(ownLast, notownLast - price);
            notown = max(notownLast, ownLast + price - fee);

            ownLast = own;
            notownLast = notown;
        }
        return max(own, notown);
    }
};