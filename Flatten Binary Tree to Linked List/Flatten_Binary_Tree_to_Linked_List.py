# Runtime: 44 ms, faster than 97.20% of Python3 online submissions for Flatten Binary Tree to Linked List.
# Memory Usage: 12.7 MB, less than 0.96% of Python3 online submissions for Flatten Binary Tree to Linked List.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: 'TreeNode') -> 'None':
        """
        Do not return anything, modify root in-place instead.
        """
        self.helper(root)
    def helper(self, root):
        if root is None or (root.left is None and root.right is None):
            return root
        leftlastNode = self.helper(root.left)
        rightlastNode = self.helper(root.right)

        if leftlastNode is not None:
            rightNode = root.right
            root.right = root.left
            root.left = None
            leftlastNode.right = rightNode
        
        return leftlastNode if rightlastNode is None else rightlastNode
