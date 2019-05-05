# 递归版本的
# Runtime: 48 ms, faster than 31.94% of Python3 online submissions for Reverse Linked List.
# Memory Usage: 18.9 MB, less than 8.90% of Python3 online submissions for Reverse Linked List.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        
        tail = head.next
        head.next = None
        reverseHead = self.reverseList(tail)
        tail.next = head

        return reverseHead