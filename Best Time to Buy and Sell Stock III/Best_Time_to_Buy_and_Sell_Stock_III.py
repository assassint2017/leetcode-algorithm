# Runtime: 68 ms, faster than 59.03% of Python3 online submissions for Best Time to Buy and Sell Stock III.
# Memory Usage: 7.2 MB, less than 78.93% of Python3 online submissions for Best Time to Buy and Sell Stock III.
class Solution:
    def maxProfit(self, prices: 'List[int]') -> 'int':
        if len(prices) < 2:
            return 0
        buy = [-prices[0] for i in range(3)]
        buy[0] = 0
        sell = [0 for i in range(3)]

        for i in range(1, len(prices)):
            for j in range(2, 0, -1):
                sell[j] = max(sell[j], buy[j] + prices[i])
                buy[j] = max(buy[j], sell[j - 1] - prices[i])
        return sell[2]