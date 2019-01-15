# 64ms 65.08%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        queue = []
        queue.append(root)  
        
        sum = 0
        while len(queue) > 0:
            root = queue.pop(0)

            if root.left is not None and root.left.left is None and root.left.right is None:
                sum += root.left.val
            if root.left:
                queue.append(root.left)
            if root.right:
                queue.append(root.right)
        return sum