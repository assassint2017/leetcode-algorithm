# Runtime: 68 ms, faster than 18.16% of Python online submissions for Linked List Cycle.
# Memory Usage: 16.2 MB, less than 89.08% of Python online submissions for Linked List Cycle.

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None:
            return False
        fastPtr = head.next
        slowPtr = head

        while fastPtr != slowPtr:
            if slowPtr.next is not None and fastPtr.next is not None and fastPtr.next.next is not None:
                slowPtr = slowPtr.next
                fastPtr = fastPtr.next.next
            else:
                return False
        return True