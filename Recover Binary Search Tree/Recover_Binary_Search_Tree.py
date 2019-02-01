# 思路二的py代码
# 104ms 98.65%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        curNode = root
        preNode, lastNode = None, None
        vec = []

        while curNode:
            if curNode.left is None:
                if lastNode and lastNode.val > curNode.val:
                    vec.append(lastNode)
                    vec.append(curNode)
                lastNode = curNode
                curNode = curNode.right
            else:
                preNode = curNode.left
                while preNode.right and preNode.right != curNode:
                    preNode = preNode.right
                if preNode.right is None:
                    preNode.right = curNode
                    curNode = curNode.left
                else:
                    preNode.right = None
                    if (preNode.val > curNode.val):
                        vec.append(preNode)
                        vec.append(curNode)
                    lastNode = curNode
                    curNode = curNode.right
        vec[0].val, vec[-1].val = vec[-1].val, vec[0].val