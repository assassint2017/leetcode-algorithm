# Runtime: 72 ms, faster than 39.39% of Python3 online submissions for House Robber III.
# Memory Usage: 15.8 MB, less than 5.09% of Python3 online submissions for House Robber III.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        hashmap = dict()
        return self.helper(root, hashmap)
    def helper(self, root, hashmap):
        if root is None:
            return 0
        if root not in hashmap:
            notrobfirst = self.helper(root.left, hashmap) + self.helper(root.right, hashmap)
            robfirst = root.val
            if root.left and root.right:
                robfirst += (self.helper(root.left.left, hashmap) +
                            self.helper(root.left.right, hashmap) +
                            self.helper(root.right.left, hashmap) +
                            self.helper(root.right.right, hashmap))
            elif root.left:
                robfirst += self.helper(root.left.left, hashmap) + self.helper(root.left.right, hashmap)
            elif root.right:
                robfirst += self.helper(root.right.left, hashmap) + self.helper(root.right.right, hashmap)
            
            hashmap[root] = max(robfirst, notrobfirst)
        return hashmap[root]
