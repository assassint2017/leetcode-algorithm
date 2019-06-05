# 思路三的py代码
# Runtime: 44 ms, faster than 97.28% of Python3 online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
# Memory Usage: 13.2 MB, less than 45.25% of Python3 online submissions for Construct Binary Tree from Preorder and Postorder Traversal.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        
        hashMap = dict()

        for index in range(len(post)):
            hashMap[post[index]] = index

        return self.helper(pre, post, 0, len(pre) - 1, 0, len(post) - 1, hashMap)
        
    def helper(self, pre, post, preLeft, preRight, postLeft, postRight, hashMap):
        
        node = None

        if preLeft <= preRight and postLeft <= postRight:
            
            node = TreeNode(pre[preLeft])

            if preLeft == preRight:
                return node
            
            length = hashMap[pre[preLeft + 1]] - postLeft + 1

            node.left = self.helper(pre, post, preLeft + 1, preLeft + length, postLeft, postLeft + length - 1, hashMap)
            node.right = self.helper(pre, post, preLeft + length + 1, preRight, postLeft + length, postRight - 1, hashMap)

        return node