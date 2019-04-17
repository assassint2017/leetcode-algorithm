# Runtime: 56 ms, faster than 53.52% of Python3 online submissions for Find Bottom Left Tree Value.
# Memory Usage: 15.6 MB, less than 14.29% of Python3 online submissions for Find Bottom Left Tree Value.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        queue = []
        queue.append(root)        

        res = root.val
        while queue:
            size = len(queue) - 1
            root = queue.pop(0)

            res = root.val
            if root.left:
                queue.append(root.left)
            if root.right:
                queue.append(root.right)

            for _ in range(size):
                root = queue.pop(0)
                if root.left:
                    queue.append(root.left)
                if root.right:
                    queue.append(root.right)

        return res