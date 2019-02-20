# Runtime: 68 ms, faster than 15.28% of Python3 online submissions for Delete Node in a Linked List.
# Memory Usage: 12.6 MB, less than 82.93% of Python3 online submissions for Delete Node in a Linked List.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        nextNode = None
        while True:
            nextNode = node.next
            node.val = nextNode.val

            if nextNode.next:
                node = nextNode
            else:
                node.next = None
                del nextNode
                break