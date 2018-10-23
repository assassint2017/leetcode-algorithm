# 94/96
# 在第95个测试用例的时候超时了
# 但是总之思路应该是没有问题的

class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        def search(start_index, end_index):
            if not heights[start_index: end_index + 1]:
                return

            height = min(heights[start_index: end_index + 1])
            height_index = heights[start_index: end_index + 1].index(height) + start_index

            area.append(height * (end_index - start_index + 1))

            if start_index >= end_index:
                return
            else:
                search(start_index, height_index - 1)
                search(height_index + 1, end_index)

        area = []
        search(0, len(heights) - 1)
        return max(area) if area else 0

