# Runtime: 188 ms, faster than 99.67% of Python online submissions for Intersection of Two Linked Lists.
# Memory Usage: 40.9 MB, less than 100.00% of Python online submissions for Intersection of Two Linked Lists.

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        lena, lenb = 0, 0

        temp = headA
        while temp:
            lena += 1
            temp = temp.next
        
        temp = headB
        while temp:
            lenb += 1
            temp = temp.next
        
        if lena is 0 or lenb is 0:
            return None

        if lena >= lenb:
            longer = headA
            shorter = headB
        else:
            longer = headB
            shorter = headA

        for i in range(abs(lena - lenb)):
            longer = longer.next
        
        while longer != shorter:
            longer = longer.next
            shorter = shorter.next

        return longer