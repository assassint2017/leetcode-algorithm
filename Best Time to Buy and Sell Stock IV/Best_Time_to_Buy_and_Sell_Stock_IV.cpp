// 思路一 基于备忘录的自顶向下的动态规划
// Runtime: 32 ms, faster than 26.23% of C++ online submissions for Best Time to Buy and Sell Stock IV.
// Memory Usage: 10.4 MB, less than 2.65% of C++ online submissions for Best Time to Buy and Sell Stock IV.

class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int length = prices.size();

        // 如果k足够大，那就是没限制，这时候可以用高效的one pass的方式解决问题
        if (k >= length / 2)
        {
            int res = 0;
            for (int i = 1; i < length; i++)
                    res += max(prices[i] - prices[i - 1], 0);
            return res;
        }

        int **buymemo = new int*[prices.size()];
        int **sellmemo = new int*[prices.size()];
        for (int i = 0; i < length; i++)
        {
            buymemo[i] = new int[k + 1];
            sellmemo[i] = new int[k + 1];

            for (int j = 0; j <= k; j++)
            {
                buymemo[i][j] = -99;
                sellmemo[i][j] = -99;
            }
        }

        int res = sell(length - 1, k, prices, sellmemo, buymemo);    
        
        delete[] buymemo;
        delete[] sellmemo;

        return res;
    }

    int buy(int i, int j, vector<int>& prices, int **buymemo, int **sellmemo)
    {
        if (i < 0 || j == 0)
            return 0;
        else if (i == 0)
            return -prices[0];
        else if (buymemo[i][j] == -99)
            buymemo[i][j] = max(buy(i - 1, j, prices, buymemo, sellmemo), sell(i - 1, j - 1, prices, sellmemo, buymemo) - prices[i]);
        return buymemo[i][j];
    }

    int sell(int i, int j, vector<int>& prices, int **sellmemo, int **buymemo)
    {
        if (i <= 0 || j == 0)
            return 0;
        else if (sellmemo[i][j] == -99)
            sellmemo[i][j] = max(sell(i - 1, j, prices, sellmemo, buymemo), buy(i - 1, j, prices, buymemo, sellmemo) + prices[i]);
        return sellmemo[i][j];
    }
};


// 思路二 自底向上的动态规划
// Runtime: 12 ms, faster than 28.39% of C++ online submissions for Best Time to Buy and Sell Stock IV.
// Memory Usage: 5.1 MB, less than 2.65% of C++ online submissions for Best Time to Buy and Sell Stock IV.
class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        if (prices.size() < 2 || k == 0)
            return 0;

        // 如果k足够大，那就是没限制，这时候可以用高效的one pass的方式解决问题
        if (k > prices.size() / 2)
        {
            int res = 0;
            for (int i = 1; i < prices.size(); i++)
                if (prices[i] - prices[i - 1] > 0)
                    res += (prices[i] - prices[i - 1]);
            return res;
        }

        int *buy = new int[k + 1];
        int *sell = new int[k + 1]();
        buy[0] = 0;
        for (int i = 1; i <= k; i++)
            buy[i] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = k; j >= 1; j--)
            {
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            }
        }
        int res = sell[k];

        delete[] sell;
        delete[] buy;

        return res;
    }
};