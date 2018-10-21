# 56ms 96.14%
class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return None
        
        mid = head
        stack, flag, last_node = [], True, ListNode(0)
        
        while True:
            for i in range(k):
                stack.append(mid)
                mid = mid.next
                if mid is None and i < k - 1:
                    return head
            
            reverse_head = reverse_mid = stack.pop()
            
            if flag:
                head = reverse_mid
                flag = False
            
            while stack:    
                reverse_mid.next = stack.pop()
                reverse_mid = reverse_mid.next
            
            reverse_mid.next = mid
            last_node.next = reverse_head
            last_node = reverse_mid

            if mid is None:
                return head