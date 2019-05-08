# Runtime: 84 ms, faster than 79.50% of Python3 online submissions for Search in a Binary Search Tree.
# Memory Usage: 15.2 MB, less than 5.30% of Python3 online submissions for Search in a Binary Search Tree.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        while root:
            if root.val == val:
                break
            elif root.val > val:
                root = root.right
            else:
                root = root.left;
        return root