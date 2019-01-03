# 第一种思路 二叉树的最小高度等于 左右子树的最小高度+1 但是要注意多一个判断条件
# 76ms 33.76%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        
        depthLeft = self.minDepth(root.left)
        depthRight = self.minDepth(root.right)
        
        if depthLeft is 0 or depthRight is 0:
            return max(depthLeft, depthRight) + 1
        else:
            return min(depthLeft, depthRight) + 1
        
        