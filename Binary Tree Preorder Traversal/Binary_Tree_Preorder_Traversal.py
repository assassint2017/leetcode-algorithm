# 52ms 99.00%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        values = []
        treeStack = []

        if (root is None):
            return values
        while root or len(treeStack) > 0:
            while root:
                values.append(root.val)
                treeStack.append(root)
                root = root.left
            if len(treeStack) > 0:
                root = treeStack.pop()
                root = root.right
        return values