# Runtime: 76 ms, faster than 47.31% of Python3 online submissions for Valid Palindrome.
# Memory Usage: 6.7 MB, less than 79.51% of Python3 online submissions for Valid Palindrome.
class Solution:
    def isPalindrome(self, s: 'str') -> 'bool':
        leftPtr, rightPtr = 0, len(s) - 1
        while (leftPtr <= rightPtr):
            while (leftPtr <= rightPtr and not self.judge(s[leftPtr])):
                leftPtr += 1
            while (leftPtr <= rightPtr and not self.judge(s[rightPtr])):
                rightPtr -= 1
            if (leftPtr > rightPtr):
                break
            if (s[leftPtr] == s[rightPtr] or self.iscase(s[leftPtr], s[rightPtr])):
                leftPtr += 1
                rightPtr -= 1
            else:
                return False
        return True
    
    def judge(self, letter):
        return (('a' <= letter <= 'z') or 
                ('A' <= letter <= 'Z') or 
                ('0' <= letter <= '9'))
    
    def iscase(self, letter1, letter2):
        return ((letter1 < '0' or letter1 > '9') and 
                (letter2 < '0' or letter2 > '9') and
                (abs(ord(letter2) - ord(letter1)) is 32))
