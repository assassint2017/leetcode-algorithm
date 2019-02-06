# Runtime: 40 ms, faster than 96.33% of Python3 online submissions for Best Time to Buy and Sell Stock with Cooldown.
# Memory Usage: 6.6 MB, less than 83.65% of Python3 online submissions for Best Time to Buy and Sell Stock with Cooldown

class Solution:
    def maxProfit(self, prices: 'List[int]') -> 'int':
        if len(prices) <= 1:
            return 0
        elif len(prices) is 2:
            return max(prices[1] - prices[0], 0)
        else:
            ownLast = -min(prices[0], prices[1])
            notownLast = max(prices[1] - prices[0], 0)
            notownLast2 = 0

            for i in range(2, len(prices)):
                own = max(ownLast, notownLast2 - prices[i])
                notown = max(notownLast, ownLast + prices[i])

                ownLast = own
                notownLast2 = notownLast
                notownLast = notown
            return max(own, notown)