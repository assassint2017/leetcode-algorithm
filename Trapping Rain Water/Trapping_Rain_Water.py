# 根据答案给出的双指针法
# 48ms 82.75%
class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height) - 1
        left_max = right_max = 0
        area = 0
        while left < right:
            if height[left] <= height[right]:
                left_max = max(height[left], left_max)
                area += left_max - height[left]
                left += 1
            else:
                right_max = max(height[right], right_max)
                area += right_max - height[right]
                right -= 1
        return area