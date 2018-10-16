# 124ms 99.38%
class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        len_string = len(s)
        index = num = 0
        for index in range(len_string):
            if s[index] is 'M':
                num += 1000
            elif s[index] is 'D':
                num += 500
            elif s[index] is 'L':
                num += 50
            elif s[index] is 'V':
                num += 5
            elif s[index] is 'C':
                if index < len_string - 1 and (s[index + 1] is 'D' or s[index + 1] is 'M'):
                    num -= 100
                else:
                    num += 100
            elif s[index] is 'X':
                if index < len_string - 1 and (s[index + 1] is 'L' or s[index + 1] is 'C'):
                    num -= 10
                else:
                    num += 10
            elif s[index] is 'I':
                if index < len_string - 1 and (s[index + 1] is 'V' or s[index + 1] is 'X'):
                    num -= 1
                else:
                    num += 1
        return num  