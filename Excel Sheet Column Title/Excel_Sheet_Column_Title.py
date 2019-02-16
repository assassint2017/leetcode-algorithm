# Runtime: 32 ms, faster than 100.00% of Python3 online submissions for Excel Sheet Column Title.
# Memory Usage: 12.7 MB, less than 100.00% of Python3 online submissions for Excel Sheet Column Title.

class Solution:
    def convertToTitle(self, n: 'int') -> 'str':
        string = []
        while n > 0:
            if n % 26 is 0:
                char = 'Z'
                n //= 26
                n -= 1
            else:
                char = chr(ord('A') + n % 26 - 1)
                n //= 26
            string.append(char)
        return ''.join(string[::-1])
