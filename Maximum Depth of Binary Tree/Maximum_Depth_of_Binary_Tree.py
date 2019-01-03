# 思路一 二叉树的高度等于 max(depth(左子树), depth(右子树)) + 1 利用递归求解
# 72ms 35.60%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        if root.left is None and root.right is None:
            return 1
        
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1