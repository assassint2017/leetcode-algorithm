# 非常直接的解决方法
# 60ms 52.08%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
         
        mid = head
        
        while mid.next is not None:
            if mid.val == mid.next.val:
                mid.next = mid.next.next    
            else:
                mid = mid.next
        return head