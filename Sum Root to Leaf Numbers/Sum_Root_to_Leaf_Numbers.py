# 76ms 15.38%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        treeStack = []
        lastNode = None
        sum = temp = 0

        while root or len(treeStack) > 0:
            while root:
                temp *= 10
                temp += root.val

                if root.left is None and root.right is None:
                    sum += temp
                treeStack.append(root)

                root = root.left
            if len(treeStack) > 0:
                root = treeStack.pop()

                if root.right is None or root.right == lastNode:
                    temp -= root.val
                    temp /= 10
                    lastNode = root
                    root = None
                else:
                    treeStack.append(root)
                    root = root.right
        return int(sum)