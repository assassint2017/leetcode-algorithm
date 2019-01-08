# 88ms 46.92%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """

        if n < 1:
            return []
        else:
            return self.helper(1, n)
    
    def helper(self, left, right):
        trees = []

        if left > right:
            trees.append(None)
        elif left == right:
            trees.append(TreeNode(left))
        else:
            for i in range(left, right + 1):
                leftTree = self.helper(left, i - 1)
                rightTree = self.helper(i + 1, right)

                for leftIter in leftTree:
                    for rightIter in rightTree:
                        root = TreeNode(i)
                        root.left = leftIter
                        root.right = rightIter

                        trees.append(root)
        return trees