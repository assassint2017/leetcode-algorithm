# 32ms 100%
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        mapping = {'1': '',
                   '2': 'abc',
                   '3': 'def',
                   '4': 'ghi',
                   '5': 'jkl',
                   '6': 'mno',
                   '7': 'pqrs',
                   '8': 'tuv',
                   '9': 'wxyz'
                  }
        if len(digits) is 0:
            return []
        elif len(digits) is 1:
            return list(mapping[digits[0]])
        else:
            pre = self.letterCombinations(digits[:-1])
            last = mapping[digits[-1]]
            
            return [pre_com + last_com for pre_com in pre for last_com in last]