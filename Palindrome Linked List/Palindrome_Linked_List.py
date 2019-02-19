# Runtime: 76 ms, faster than 82.31% of Python3 online submissions for Palindrome Linked List.
# Memory Usage: 22.9 MB, less than 100.00% of Python3 online submissions for Palindrome Linked List.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: 'ListNode') -> 'bool':
        if head is None or head.next is None:
            return True
        
        midPtr, fastPtr = head, head
        while fastPtr.next and fastPtr.next.next:
            midPtr = midPtr.next
            fastPtr = fastPtr.next.next

        even = True if fastPtr.next else False

        rightHead = midPtr.next

        preNode, curNode = None, head
        while curNode != rightHead:
            nextNode = curNode.next
            curNode.next = preNode
            preNode = curNode
            curNode = nextNode
        
        leftHead = midPtr if even else midPtr.next

        res = True
        templeftHead, temprightHead = leftHead, rightHead
        while templeftHead:
            if templeftHead.val != temprightHead.val:
                res = False
                break
            else:
                templeftHead = templeftHead.next
                temprightHead = temprightHead.next
        
        preNode, curNode = None, midPtr
        while curNode:
            nextNode = curNode.next
            curNode.next = preNode
            preNode = curNode
            curNode = nextNode

        midPtr.next = rightHead

        return res