# Runtime: 100 ms, faster than 76.02% of Python3 online submissions for N-ary Tree Preorder Traversal.
# Memory Usage: 17.6 MB, less than 74.45% of Python3 online submissions for N-ary Tree Preorder Traversal.

"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        
        res = []

        if root is None:
            return res
        
        treeStack = []
        treeStack.append(root)

        while treeStack:

            root = treeStack.pop()

            for i in range(len(root.children) - 1, -1, -1):
                treeStack.append(root.children[i])
            
            res.append(root.val)

        return res