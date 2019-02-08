# Runtime: 44 ms, faster than 99.63% of Python online submissions for Linked List Cycle II.
# Memory Usage: 16.2 MB, less than 94.55% of Python online submissions for Linked List Cycle II.

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        fastPtr, slowPtr = head, head
        hasCycle = False
        while (slowPtr.next is not None and fastPtr.next is not None and fastPtr.next.next is not None):
            slowPtr = slowPtr.next
            fastPtr = fastPtr.next.next
            if slowPtr == fastPtr:
                hasCycle = True
                break
        if not hasCycle:
            return None
        fastPtr = head
        while fastPtr != slowPtr:
            slowPtr = slowPtr.next
            fastPtr = fastPtr.next
        return fastPtr