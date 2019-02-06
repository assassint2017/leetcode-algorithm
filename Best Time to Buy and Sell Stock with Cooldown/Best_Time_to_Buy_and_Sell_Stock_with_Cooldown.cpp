//动态规划

// own[i] = max(own[i-1], not_own[i-2] - prices[i])
// not_own[i] = max(not_own[i-1], own[i-1] + prices[i])

// Runtime: 8 ms, faster than 33.09% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
// Memory Usage: 6.2 MB, less than 1.87% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() <= 1)
            return 0;
        else if (prices.size() == 2)
            return max(prices[1] - prices[0], 0);

        int ownLast = -min(prices[0], prices[1]);
        int notownLast = max(prices[1] - prices[0], 0);
        int notownLast2 = 0;

        int own, notown;
        for (int i = 2; i < prices.size(); i++)
        {
            own = max(ownLast, notownLast2 - prices[i]);
            notown = max(notownLast, ownLast + prices[i]);

            ownLast = own;
            notownLast2 = notownLast;
            notownLast = notown;
        }
        return max(own, notown);
    }
};

