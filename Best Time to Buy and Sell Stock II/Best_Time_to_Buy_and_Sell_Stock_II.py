# Runtime: 40 ms, faster than 97.81% of Python3 online submissions for Best Time to Buy and Sell Stock II.
# Memory Usage: 7.2 MB, less than 89.70% of Python3 online submissions for Best Time to Buy and Sell Stock II.

class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        return sum([prices[i] - prices[i - 1] for i in range(1, len(prices)) if prices[i] > prices[i - 1]])
        