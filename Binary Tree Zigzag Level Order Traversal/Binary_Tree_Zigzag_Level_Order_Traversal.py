# 56ms 41.18%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        values = []
        if root is None:
            return values
        
        queue = []
        queue.append(root)

        leftToRight = True

        while len(queue) > 0:
            value = []
            size = len(queue)
            
            if not leftToRight:
                value = [0 for _ in range(size)]

            while size > 0:
                tempNode = queue.pop(0)

                if leftToRight:
                    value.append(tempNode.val)
                else:
                    value[size - 1] = tempNode.val

                if tempNode.left:
                    queue.append(tempNode.left)
                if tempNode.right:
                    queue.append(tempNode.right)

                size -= 1
            values.append(value)
            leftToRight = not leftToRight
        return values