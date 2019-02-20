# 思路五的py代码
# Runtime: 408 ms, faster than 69.87% of Python3 online submissions for Palindrome Partitioning II.
# Memory Usage: 31 MB, less than 26.47% of Python3 online submissions for Palindrome Partitioning II.
class Solution:
    def minCut(self, s: 'str') -> 'int':
        if len(s) < 2:
            return 0
        
        memo = [[False for j in range(len(s))] for i in range(len(s))]
        
        res = [float('inf') for i in range(len(s) + 1)]
        res[len(s)] = -1

        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)):
                if s[i] == s[j] and (j - i < 2 or memo[i + 1][j - 1]):
                    memo[i][j] = True
                    res[i] = min(res[i], res[j + 1] + 1)
        
        return res[0]