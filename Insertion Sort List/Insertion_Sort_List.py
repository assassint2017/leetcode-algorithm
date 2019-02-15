# Runtime: 1324 ms, faster than 50.00% of Python3 online submissions for Insertion Sort List.
# Memory Usage: 14.6 MB, less than 100.00% of Python3 online submissions for Insertion Sort List.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: 'ListNode') -> 'ListNode':
        if head is None or head.next is None:
            return head

        preNode, curNode, nextNode = None, head, head
        while curNode:
            nextNode = nextNode.next

            leftNode, rightNode = None, head
            insert = False
            while rightNode != curNode:
                if rightNode.val <= curNode.val:
                    leftNode = rightNode
                    rightNode = rightNode.next
                else:
                    insert = True
                    curNode.next = rightNode

                    if leftNode:
                        leftNode.next = curNode
                    else:
                        head = curNode
                    
                    preNode.next = nextNode
                    break
            
            if not insert:
                preNode = curNode

            curNode = nextNode
        
        return head