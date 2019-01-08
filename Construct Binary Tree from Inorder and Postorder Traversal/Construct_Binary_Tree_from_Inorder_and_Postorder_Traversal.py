# 160ms 81.93%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        return self.helper(0, len(postorder) - 1, 0, len(inorder) - 1, postorder, inorder)
        
    def helper(self, postLeft, postRight, inLeft, inRight, postorder, inorder):
        if postLeft > postRight:
            return None
        elif postLeft == postRight:
            return TreeNode(postorder[postRight])
        else:
            rootValue = postorder[postRight]
            rootIndex = inorder.index(rootValue)

            root = TreeNode(rootValue)
            root.left = self.helper(postLeft, postLeft + rootIndex - inLeft - 1, inLeft, rootIndex - 1, postorder, inorder)
            root.right = self.helper(postLeft + rootIndex - inLeft, postRight - 1, rootIndex + 1, inRight, postorder, inorder)

            return root
        