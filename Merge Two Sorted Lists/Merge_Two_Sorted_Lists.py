# 基本思路就是将一个链表不断插入到另外一个链表中
# 44ms 99.41%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1:
            return l2
        if not l2:
            return l1

        main, sub = (l2, l1) if l1.val > l2.val else (l1, l2)
        
        main_mid = main
        sub_mid = sub

        while main_mid.next is not None:
            if main_mid.next.val >= sub_mid.val:
                
                temp_node = sub_mid
                sub_mid = sub_mid.next
                
                next_node = main_mid.next
                main_mid.next = temp_node
                temp_node.next = next_node
                
                main_mid = temp_node
                
                if sub_mid is None:
                    return main   
            else:
                main_mid = main_mid.next
        main_mid.next = sub_mid
        return main