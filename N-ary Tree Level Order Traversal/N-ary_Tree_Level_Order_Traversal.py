# Runtime: 108 ms, faster than 29.24% of Python3 online submissions for N-ary Tree Level Order Traversal.
# Memory Usage: 17.6 MB, less than 54.44% of Python3 online submissions for N-ary Tree Level Order Traversal.

"""
# Definition for a Node.w
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        res = []

        if root is None:
            return res
        
        treeQueue = []
        treeQueue.append(root)

        while treeQueue:

            vec = []
            for i in range(len(treeQueue)):

                root = treeQueue[0]
                treeQueue.pop(0)

                for node in root.children:
                    treeQueue.append(node)
                
                vec.append(root.val)
            
            res.append(vec)

        return res