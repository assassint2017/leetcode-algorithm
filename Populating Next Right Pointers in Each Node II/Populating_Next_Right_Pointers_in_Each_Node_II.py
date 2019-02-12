# Runtime: 56 ms, faster than 68.67% of Python online submissions for Populating Next Right Pointers in Each Node II.
# Memory Usage: 13.1 MB, less than 0.91% of Python online submissions for Populating Next Right Pointers in Each Node II.

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
        while True:
            leftfirsrNode = None
            while root:
                if root.left or root.right:
                    leftfirsrNode = root
                    break
                root = root.next

            if leftfirsrNode is None:
                return
            
            while True:
                nextNode = root.next
                while nextNode:
                    if nextNode.left or nextNode.right:
                        break
                    nextNode = nextNode.next
                if nextNode is None:
                    if root.left and root.right:
                        root.left.next = root.right
                    break
                
                if root.left:
                    if root.right:
                        root.left.next = root.right
                    else:
                        if nextNode.left:
                            root.left.next = nextNode.left
                        else:
                            root.left.next = nextNode.right
                if root.right:
                    if nextNode.left:
                        root.right.next = nextNode.left
                    else:
                        root.right.next = nextNode.right
                root = nextNode
            root = leftfirsrNode.left if leftfirsrNode.left else leftfirsrNode.right