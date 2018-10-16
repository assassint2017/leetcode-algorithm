# 第一种思路，将数字转换为字符串 
# 252ms 99.32%
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        strs = str(x)
        return True if strs == strs[::-1] else False

# 第二种思路，把数字翻转过来判断两者是否相等
# 268ms 90.11%
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        reverse, temp_x = 0, x
        while x >= 10:
            reverse = reverse * 10 + x % 10
            x //= 10
        reverse = reverse * 10 + x
        return True if reverse == temp_x else False
    
# 第三种思路，不必翻转所有的数据，只需要翻转一半就可以了
# 260ms 97.20%
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x % 10 is 0 and x is not 0):
            return False
        reverse = 0
        while x > reverse:
            reverse = reverse * 10 + x % 10
            x //= 10
        return True if reverse == x or reverse // 10 == x else False