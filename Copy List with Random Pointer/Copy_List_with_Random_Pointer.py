# 思路二的py代码
# Runtime: 72 ms, faster than 71.62% of Python online submissions for Copy List with Random Pointer.
# Memory Usage: 20 MB, less than 100.00% of Python online submissions for Copy List with Random Pointer.

# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if head is None:
            return None
        
        originNode = head
        while originNode:
            copyNode = RandomListNode(originNode.label)
            copyNode.next = originNode.next
            originNode.next = copyNode

            originNode = originNode.next.next
        
        originNode = head
        while originNode:
            if originNode.random:
                originNode.next.random = originNode.random.next
            originNode = originNode.next.next

        dummyNode = RandomListNode(0)
        preNode = dummyNode
        while head:
            copyNode = head.next
            head.next = copyNode.next
            copyNode.next = None
            preNode.next = copyNode
            preNode = copyNode
            head = head.next
        
        return dummyNode.next
        