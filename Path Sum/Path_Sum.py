# 第一种思路 使用递归
# 76ms 39.18%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        # 如果是空树，则直接返回
        if root is None:
            return False
        
        # 如果查询到了叶子节点
        if root.left is None and root.right is None:
            if sum == root.val:
                return True
            else:
                return False
        
        return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)
        