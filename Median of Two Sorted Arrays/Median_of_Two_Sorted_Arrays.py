# 96 ms 93.73%
# 借鉴答案的解题思路
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m, n = len(nums1), len(nums2)

        if n < m:
            return self.findMedianSortedArrays(nums2, nums1)
        
        start, end = 0, m
        
        while start <= end:
            
            i = (start + end) // 2
            # 这里由于不管m+n是基数还是偶数，地板除把这两种情况统一为下面的一个公式了
            j = (m + n + 1) // 2 - i

            a_left = nums1[i - 1] if i != 0 else float('-inf')
            a_right = nums1[i] if i != m else float('inf')

            b_left = nums2[j - 1] if j != 0 else float('-inf')
            b_right = nums2[j] if j != n else float('inf')
            
            if b_right >= a_left and a_right >= b_left:
                break
            elif a_right < b_left:
                start = i + 1
            else:
                end = i - 1
        
        if (m + n) % 2 is 0:
            return (max(a_left, b_left) + min(a_right, b_right)) / 2
        else:
            # 如果是奇数的话，根据j的公式，中位数会出现在左边
            # 所以只需要从左边的两个边界值寻找就行了
            return max(a_left, b_left)