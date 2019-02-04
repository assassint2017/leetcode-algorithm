# Runtime: 44 ms, faster than 73.23% of Python3 online submissions for Best Time to Buy and Sell Stock.
# Memory Usage: 7.2 MB, less than 33.96% of Python3 online submissions for Best Time to Buy and Sell Stock.

class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if (len(prices) < 2):
            return 0

        res = 0
        buyday = prices[0]

        for i in range(1, len(prices)):
            buyday = min(buyday, prices[i])
            res = max(res, prices[i] - buyday)
        return res