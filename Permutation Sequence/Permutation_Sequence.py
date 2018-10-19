# 按位确定
# 40ms 84.01%
class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        def factorial(num):
            if num is 0:
                return 1
            else:
                return num * factorial(num - 1)
            
        res_list = ''
        temp_list = list(range(1, n + 1))
        k -= 1
        
        while n > 0:
            temp = factorial(n - 1)
            res_list += str(temp_list[k // temp])
            del temp_list[k // temp]
            k = k - k // temp * temp
            n -= 1

        return res_list