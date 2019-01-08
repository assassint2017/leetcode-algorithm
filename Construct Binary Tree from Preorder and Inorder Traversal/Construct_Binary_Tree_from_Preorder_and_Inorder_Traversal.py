# 152ms 80.48%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        return self.helper(0, len(preorder) - 1, 0, len(inorder), preorder, inorder)
        
    def helper(self, preLeft, preRight, inLeft, inRight, preorder, inorder):
        if preLeft > preRight:
            return None
        elif preLeft == preRight:
            return TreeNode(preorder[preLeft])
        else:
            rootValue = preorder[preLeft] 
            rootIndex = inorder.index(rootValue)

            root = TreeNode(rootValue)
            root.left = self.helper(preLeft + 1, preLeft + rootIndex - inLeft, inLeft, rootIndex - 1, preorder, inorder)
            root.right = self.helper(preLeft + rootIndex - inLeft + 1, preRight, rootIndex + 1, inRight, preorder, inorder)

            return root