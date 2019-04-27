# Runtime: 60 ms, faster than 13.36% of Python3 online submissions for Find the Difference.
# Memory Usage: 13.3 MB, less than 5.00% of Python3 online submissions for Find the Difference.

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        vec = [0 for i in range(26)]

        for char in s:
            vec[ord(char) - 97] += 1
        
        for char in t:
            vec[ord(char) - 97] -= 1
            if vec[ord(char) - 97] == -1:
                return char