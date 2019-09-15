# Runtime: 664 ms, faster than 32.94% of Python3 online submissions for Maximum Depth of N-ary Tree.
# Memory Usage: 95.3 MB, less than 8.33% of Python3 online submissions for Maximum Depth of N-ary Tree.

"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0
        
        res = 0
        for children in root.children:
            res = max(res, self.maxDepth(children))
        
        return res + 1