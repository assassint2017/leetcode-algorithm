# 思路二的py代码

# Runtime: 92 ms, faster than 90.54% of Python3 online submissions for Reorder List.
# Memory Usage: 18.3 MB, less than 48.63% of Python3 online submissions for Reorder List.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: 'ListNode') -> 'None':
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None or head.next.next is None:
            return
        slowPtr, fastPtr = head, head
        while fastPtr.next is not None and fastPtr.next.next is not None:
            slowPtr = slowPtr.next
            fastPtr = fastPtr.next.next
        
        preNode = slowPtr
        fastPtr = slowPtr.next
        slowPtr.next = None
        while fastPtr is not None:
            nextNode = fastPtr.next
            fastPtr.next = preNode
            preNode = fastPtr
            fastPtr = nextNode
        fastPtr = preNode

        slowPtr = head
        while slowPtr != fastPtr and slowPtr is not None:
            tempFast = fastPtr
            tempSlow = slowPtr

            fastPtr = fastPtr.next
            slowPtr = slowPtr.next

            tempFast.next = slowPtr
            tempSlow.next = tempFast
        
        slowPtr = None