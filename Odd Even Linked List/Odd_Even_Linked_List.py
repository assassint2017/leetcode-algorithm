# Runtime: 48 ms, faster than 89.44% of Python3 online submissions for Odd Even Linked List.
# Memory Usage: 15.1 MB, less than 6.02% of Python3 online submissions for Odd Even Linked List.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:

        oddHead = ListNode(0)
        evenHead = ListNode(0)

        oddptr = oddHead
        evenptr = evenHead

        while head:
            oddptr.next = head
            oddptr = oddptr.next
            head = head.next

            if head is None:
                break
            
            evenptr.next = head
            evenptr = evenptr.next
            head = head.next
        
        evenptr.next = None
        oddptr.next = evenHead.next

        return oddHead.next