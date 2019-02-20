# Runtime: 68 ms, faster than 100.00% of Python3 online submissions for Remove Linked List Elements.
# Memory Usage: 15.9 MB, less than 28.32% of Python3 online submissions for Remove Linked List Elements.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: 'ListNode', val: 'int') -> 'ListNode':
        
        dummyHead = ListNode(0)
        dummyHead.next = head

        preNode = dummyHead
        while head:
            if head.val == val:
                preNode.next = head.next
                del head
                head = preNode.next
            else:
                preNode = head
                head = head.next
        
        return dummyHead.next