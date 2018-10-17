# 40ms 90.52%
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def count(strs):
            res = ''
            index = 0
            len_strs = len(strs)
            
            while index < len_strs:
                num = 1
                letter = strs[index]

                while index < len_strs:
                    index += 1
                    if index >= len_strs:
                        res += (str(num) + letter)
                        break

                    if strs[index] == letter:
                        num += 1
                    else:
                        res += (str(num) + letter)
                        break
            return res

        for i in range(n):    
            if i is 0:
                temp = '1'
            else:
                temp = count(temp)
        return temp