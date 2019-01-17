# 60ms 99.56%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        values = []
        treeQueue = []
        treeQueue.append(root)

        if root is None:
            return values
        while len(treeQueue) > 0:
            size = len(treeQueue)
            while size >= 2:
                root = treeQueue.pop(0)
                if root.left:
                    treeQueue.append(root.left)
                if root.right:
                    treeQueue.append(root.right)
            
            root = treeQueue.pop(0)
            values.append(root.val)
            if root.left:
                treeQueue.append(root.left)
            if root.right:
                treeQueue.append(root.right)
                size -= 1
        return values