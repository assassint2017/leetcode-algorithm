# 第一种思路，自己写的two pass
# 40ms 99.46%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        len_listnode = 1
        if head.next is not None:
            len_listnode += 1
            mid = head.next
            while True:
                if mid.next is not None:
                    len_listnode += 1
                    mid = mid.next
                else:   
                    break
        else:
            return None
        
        if n == len_listnode:
            return head.next
        elif n == 1:
            if len_listnode == 2:
                head.next = None
                return head
            else:
                index = 1
                mid = head
                while True:
                    if index == len_listnode - 1:
                        mid.next = None
                        return head
                    else:
                        mid = mid.next
                        index += 1
        else:
            index = 1
            mid = head
            while True:
                if index == len_listnode - n:
                    mid.next = mid.next.next
                    return head
                else:
                    mid = mid.next
                    index += 1

# 第二种思路 one pass
# 40ms 99.46%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        len_listnode = 1
        pre = tail = head
        for index in range(n):
            if tail.next is not None:
                tail = tail.next
                len_listnode += 1
            else:
                break
        while tail.next is not None:
            tail = tail.next
            pre = pre.next
            len_listnode += 1
            
        # 如果移除的是最后一个节点
        if n is 1 and len_listnode is not 1:
            pre.next = None
        # 如果移除的是第一个节点            
        elif len_listnode == n:
            head = head.next
        # 如果移除的是中间的节点
        else:
            pre.next = pre.next.next
        return head