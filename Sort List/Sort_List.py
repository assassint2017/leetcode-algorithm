# Runtime: 240 ms, faster than 47.72% of Python3 online submissions for Sort List.
# Memory Usage: 20.7 MB, less than 16.07% of Python3 online submissions for Sort List.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        
        slowPtr, fastPtr = head, head
        preNode = None
        while fastPtr is not None and fastPtr.next is not None:
            preNode = slowPtr
            slowPtr = slowPtr.next
            fastPtr = fastPtr.next.next
        
        preNode.next = None

        left = self.sortList(head)
        right = self.sortList(slowPtr)

        return self.merge(left, right)

    def merge(self, left, right):
        
        dummyHead = ListNode(0)
        head = dummyHead

        while left is not None and right is not None:
            if left.val <= right.val:
                head.next = left
                head = head.next
                left = left.next
            else:
                head.next = right
                head = head.next
                right = right.next
            
        if left is not None:
            head.next = left
        if right is not None:
            head.next = right
            
        return dummyHead.next