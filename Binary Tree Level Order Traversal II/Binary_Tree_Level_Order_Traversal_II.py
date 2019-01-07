# 64ms 36.69%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        values = []
        if root is None:
            return values
        
        queue = []
        queue.append(root)

        while len(queue) > 0:
            value = []
            size = len(queue)
            while size > 0:
                tempNode = queue.pop(0)
                value.append(tempNode.val)

                if tempNode.left:
                    queue.append(tempNode.left)
                if tempNode.right:
                    queue.append(tempNode.right)

                size -= 1
            values.append(value)

        return values[::-1]