# 116ms 19.37%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def helper(left, right):
            if left > right:
                return None
            else:
                mid = (left + right) // 2

                root = TreeNode(nums[mid])
                root.left = helper(left, mid - 1)
                root.right = helper(mid + 1, right)

                return root

        return helper(0, len(nums) - 1)

    
        