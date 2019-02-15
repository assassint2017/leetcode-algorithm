# 动态规划版本的py代码

# Runtime: 40 ms, faster than 81.53% of Python3 online submissions for Interleaving String.
# Memory Usage: 12.6 MB, less than 100.00% of Python3 online submissions for Interleaving String.

class Solution:
    def isInterleave(self, s1: 'str', s2: 'str', s3: 'str') -> 'bool':
        if len(s1) + len(s2) != len(s3):
            return False
        if len(s1) is 0:
            if s2 == s3:
                return True
            else:
                return False
        if len(s2) is 0:
            if s1 == s3:
                return True
            else:
                return False
        
        memo = [True for i in range(len(s2) + 1)]
        for i in range(1, len(s2) + 1):
            if s2[0:i] == s3[0:i]:
                memo[i] = True
            else:
                memo[i] = False
        for i in range(1, len(s1) + 1):
            if s1[0:i] == s3[0:i]:
                memo[0] = True
            else:
                memo[0] = False
            for j in range(1, len(s2) + 1):
                memo[j] = (memo[j] and s1[i - 1] == s3[i + j - 1]) or (memo[j - 1] and s2[j - 1] == s3[i + j - 1])
        
        return memo[len(s2)]