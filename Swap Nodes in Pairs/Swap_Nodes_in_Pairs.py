# 36ms 97.50%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return []
        
        mid = head
        
        if mid.next is not None:
                next_node = mid.next
                mid.next = next_node.next
                next_node.next = mid
                head = next_node
        else:
            return head
                    
        while True:
            if mid.next is not None:
                last_node = mid
                mid = mid.next
            else:
                return head
            if mid.next is not None:
                next_node = mid.next
                mid.next = next_node.next
                next_node.next = mid
                
                last_node.next = next_node
            else:
                return head