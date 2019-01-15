# 56ms 80.13%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        values = []
        stack = []
        preNode = 0

        if (root is None):
            return values
        
        while root or len(stack) > 0:
            while root:
                stack.append(root)
                root = root.left
            if len(stack) > 0:
                root = stack.pop()
                if root.right is None or root.right == preNode:
                    values.append(root.val)
                    preNode = root;
                    root = None
                else:
                    stack.append(root)
                    root = root.right
        return values