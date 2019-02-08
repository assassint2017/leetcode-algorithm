# Runtime: 140 ms, faster than 36.58% of Python3 online submissions for Best Time to Buy and Sell Stock IV.
# Memory Usage: 7 MB, less than 58.00% of Python3 online submissions for Best Time to Buy and Sell Stock IV.
class Solution:
    def maxProfit(self, k: 'int', prices: 'List[int]') -> 'int':
        if len(prices) < 2 or k is 0:
            return 0
        if k > len(prices) // 2:
            return sum([prices[i] - prices[i - 1] for i in range(1, len(prices)) if prices[i] - prices[i - 1] > 0])
        buy = [-prices[0] for i in range(k + 1)]
        buy[0] = 0
        sell = [0 for i in range(k + 1)]

        for i in range(1, len(prices)):
            for j in range(k, 0, -1):
                sell[j] = max(sell[j], buy[j] + prices[i])
                buy[j] = max(buy[j], sell[j - 1] - prices[i])
        return sell[k]