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

    
# 第二种思路,使用堆栈
# 下面是一个对算法的解释
# For any bar x, if it's in a rectangle of which the height is also the height of x, 
# we know that every bar in the rectangle must be no shorter than x. 
# Then the issue is to find the left and right boundary where the bars are shorter than x. 
# According to the code, when a bar is popped out from the stack, we know it must be higher than the bar at position i, 
# so bar[i] must be the right boundary (exclusive) of the rectangle, 
# and the previous bar in the stack is the first one that is shorter than the popped one so it must be the left boundary (also exclusive). 
# Then we find the rectangle.

# 64ms 98.67%
class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights.append(0)
        stack = [-1]
        max_area = 0
        
        for i in range(len(heights)):
            while heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i - stack[-1] - 1
                max_area = max(max_area, h * w)
            stack.append(i)

        # 下面的这句主要是为了不破坏输入,所以对于ac这句话可定是多余的
        # 但是这是一个好习惯
        heights.pop()
        return max_area
