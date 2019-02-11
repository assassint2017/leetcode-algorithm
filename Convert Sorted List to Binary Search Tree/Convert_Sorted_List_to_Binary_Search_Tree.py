# Runtime: 136 ms, faster than 65.78% of Python3 online submissions for Convert Sorted List to Binary Search Tree.
# Memory Usage: 13.4 MB, less than 38.57% of Python3 online submissions for Convert Sorted List to Binary Search Tree.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: 'ListNode') -> 'TreeNode':
        if head is None:
            return None
        slowPtr, fastPtr, prePtr = head, head, None
        while fastPtr.next is not None and fastPtr.next.next is not None:
            prePtr = slowPtr
            slowPtr = slowPtr.next
            fastPtr = fastPtr.next.next
        
        treeNode = TreeNode(slowPtr.val)
        
        if prePtr is not None:
            prePtr.next = None
            treeNode.left = self.sortedListToBST(head)
            prePtr.next = slowPtr

        if slowPtr.next is not None:
            treeNode.right = self.sortedListToBST(slowPtr.next)
        
        return treeNode