# 非递归版本的py代码
# Runtime: 96 ms, faster than 91.05% of Python3 online submissions for N-ary Tree Postorder Traversal.
# Memory Usage: 17.8 MB, less than 13.20% of Python3 online submissions for N-ary Tree Postorder Traversal.

"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        
        res = []

        if root is None:
            return res
        
        treeStack = []
        treeStack.append(root)

        while treeStack:

            root = treeStack.pop()

            for node in root.children:
                treeStack.append(node)
            
            res.append(root.val)

        res.reverse()
        return res