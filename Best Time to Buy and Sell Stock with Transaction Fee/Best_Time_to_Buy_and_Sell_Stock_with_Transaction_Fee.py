# Runtime: 248 ms, faster than 78.40% of Python3 online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
# Memory Usage: 19.9 MB, less than 94.51% of Python3 online submissions for Best Time to Buy and Sell Stock with Transaction Fee.

class Solution:
    def maxProfit(self, prices: 'List[int]', fee: 'int') -> 'int':
        if len(prices) <= 1:
            return 0
        
        ownLast = -prices[0]
        notownLast = 0

        for i in range(1, len(prices)):
            own = max(ownLast, notownLast - prices[i])
            notown = max(notownLast, ownLast + prices[i] - fee)

            ownLast = own
            notownLast = notown
        return max(own, notown)