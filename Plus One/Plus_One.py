# 第一种思路，简单粗暴
# 36ms 99.84%
class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        num = 1
        len_digits = len(digits)
        for index, digit in enumerate(digits):
            num += digit * 10 ** (len_digits - index - 1)
        
        return list(map(int, list(str(num))))

# 第二种思路，使用进位制
# 36ms 99.84%
class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for index in range(len(digits) - 1, -1, -1):
            if index is len(digits) - 1:
                digits[index] += 1
            else:
                digits[index] += carry

            if digits[index] >= 10:
                carry = digits[index] // 10
                digits[index] %= 10
            else:
                carry = 0
        if carry is not 0:
            digits.insert(0, carry)
        return digits