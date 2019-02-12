# 非递归版本的py代码
# Runtime: 48 ms, faster than 84.27% of Python online submissions for Populating Next Right Pointers in Each Node.
# Memory Usage: 15.3 MB, less than 0.97% of Python online submissions for Populating Next Right Pointers in Each Node.

# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root is None:
            return
        
        while root.left is not None:
            leftfirstNode = root
            while root.next is not None:
                root.left.next = root.right
                root.right.next = root.next.left
                root = root.next
            
            root.left.next = root.right

            root = leftfirstNode.left
        