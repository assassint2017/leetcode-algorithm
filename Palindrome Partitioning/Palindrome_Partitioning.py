# Runtime: 80 ms, faster than 93.09% of Python3 online submissions for Palindrome Partitioning.
# Memory Usage: 12.8 MB, less than 100.00% of Python3 online submissions for Palindrome Partitioning.

class Solution:
    def partition(self, s: 'str') -> 'List[List[str]]':
        res = []
        vec = []

        self.helper(0, s, vec, res)

        return res

    def helper(self, start, s, vec, res):
        if start == len(s):
            # 这里传递的时候一定要注意，需要进行深度拷贝，否则res里边的东西就随着vec改变而改变
            res.append(vec[:])
            return
        for i in range(start, len(s)):
            if self.isPalindrome(s, start, i):
                vec.append(s[start: i + 1])
                self.helper(i + 1, s, vec, res)
                vec.pop()

    def isPalindrome(self, s, start, end):
        leftPtr, rightPtr = start, end
        while leftPtr <= rightPtr:
            if s[leftPtr] != s[rightPtr]:
                return False
            else:
                leftPtr += 1
                rightPtr -= 1
        return True
