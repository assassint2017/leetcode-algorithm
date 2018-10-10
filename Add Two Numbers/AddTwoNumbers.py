# 第一种思路
# 将两个链表转换为数字，然后加累加得到的结果再转换为链表，效率比较低
# 112ms 86.57%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        num1, len_listnode = 0, 0
        while True:
            num1 += (l1.val) * 10 ** (len_listnode)
            len_listnode += 1
            l1 = l1.next
            if l1 is None:
                break
        num2, len_listnode = 0, 0
        while True:
            num2 += (l2.val) * 10 ** (len_listnode)
            len_listnode += 1
            l2 = l2.next
            if l2 is None:
                break
                
        res = list(str(num1 + num2))[::-1]
        
        mid = head = ListNode(res[0])
        
        for index in range(1, len(res)):
            next_node = ListNode(res[index])
            mid.next = next_node
            mid = next_node
        
        return head

# 第二种思路
# 直接取两个链表的值然后相加，得到新的链表
# 104ms 99.34%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0  # 进位的意思
        
        temp = l1.val + l2.val
        carry = temp // 10
        mid = head = ListNode(temp % 10)
        
        while True:
            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None
            
            if l1 is l2 is None:
                break
                
            n1 = l1.val if l1 is not None else 0
            n2 = l2.val if l2 is not None else 0
        
            temp = n1 + n2 + carry
            mid.next = ListNode(temp % 10)
            mid = mid.next
            carry = temp // 10
        
        if carry is not 0:
            mid.next =ListNode(carry)
        return head