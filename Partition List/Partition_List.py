# 第一种思路，简单粗暴，使用两个列表，一个存放小节点，一个存放大节点
# 44ms 77.50%
class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        smaller_stack, greater_stack = [], []
        while head is not None:
            if head.val < x:
                smaller_stack.append(head)
            else:
                greater_stack.append(head)
            head = head.next
        for index in range(len(smaller_stack) - 1):
            smaller_stack[index].next = smaller_stack[index + 1] 
        for index in range(len(greater_stack) - 1):
            greater_stack[index].next = greater_stack[index + 1]
        
        if smaller_stack:
            head = smaller_stack[0]
            if greater_stack:
                smaller_stack[-1].next = greater_stack[0]
                greater_stack[-1].next = None
            else:
                smaller_stack[-1].next = None
        else:
            if greater_stack:
                head = greater_stack[0]
                greater_stack[-1].next = None
            else:
                return None
        return head