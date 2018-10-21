# 48ms 71.90%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return []
        
        stack = []
        len_listnode = 0
        mid = head
        while mid:
            stack.append(mid)
            mid = mid.next
            len_listnode += 1
        
        k = k - k // len_listnode * len_listnode
        
        if k is 0:
            return head
        
        stack[-1].next = stack[0]
        head = stack[-k]
        stack[-k - 1].next = None
        return head