# Runtime: 96 ms, faster than 92.22% of Python3 online submissions for Binary Tree Maximum Path Sum.
# Memory Usage: 20.1 MB, less than 100.00% of Python3 online submissions for Binary Tree Maximum Path Sum.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = -float('inf')
        self.helper(root)
        return self.res

    def helper(self, root):
        if root is None:
            return 0
        leftmax = max(0, self.helper(root.left))
        rightmax = max(0, self.helper(root.right))

        self.res = max(self.res, leftmax + rightmax + root.val)

        return max(leftmax, rightmax) + root.val
        