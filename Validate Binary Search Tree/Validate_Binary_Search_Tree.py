# 第一种思路 利用中序遍历一个二叉树，返回的结果应该是依次递增的
# 80ms 34.01%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        preValue = None
        treeStack = []

        while root or len(treeStack) > 0:
            while root:
                treeStack.append(root)
                root = root.left
            if len(treeStack) > 0:
                root = treeStack.pop()
                if preValue and root.val <= preValue.val:
                    return False
                else:
                    preValue = root
                root = root.right
        return True