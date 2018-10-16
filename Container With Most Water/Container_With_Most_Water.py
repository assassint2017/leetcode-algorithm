# 68ms 80.98%
# 典型的双指针法，一般双针织可以合理的控制程序的时间复杂度为O(n)
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        left_index, right_index = 0, len(height) - 1

        while left_index < right_index:
            area = min(height[left_index], height[right_index]) \
                   * (right_index - left_index)
            if area > max_area:
                max_area = area

            if height[left_index] < height[right_index]:
                left_index += 1
            else:
                right_index -= 1
        return max_area