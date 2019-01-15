# 192ms 14.52%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        leftMaxHeight = 0
        temp = root.left
        while temp:
            temp = temp.left
            leftMaxHeight += 1
        
        rightMaxHeight = 0
        temp = root.right
        while temp:
            temp = temp.left
            rightMaxHeight += 1

        if leftMaxHeight == rightMaxHeight:
            return self.countNodes(root.right) + (1 << leftMaxHeight)
        else:
            return self.countNodes(root.left) + (1 << rightMaxHeight)