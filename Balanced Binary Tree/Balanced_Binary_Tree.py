# 第一种思路
# 108ms 24.70%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        else:
            return abs(self.maxDepth(root.left) - self.maxDepth(root.right)) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)

    def maxDepth(self, root):
        if root is None:
            return 0
        else:
            depthLeft = self.maxDepth(root.left)
            depthRight = self.maxDepth(root.right)

            return depthLeft + 1 if depthLeft > depthRight else depthRight + 1