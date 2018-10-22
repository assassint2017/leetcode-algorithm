# 从测试用例来看，貌似升序和降序都是存在的
# 60ms 49.02%
class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = dummy = ListNode(0)
        while head:
            if head.next and head.val == head.next.val:
                while head and head.next and head.val == head.next.val:
                    head = head.next
                head = head.next
                if not head:
                    pre.next = head
            else:
                pre.next = head
                pre = head
                head = head.next
        return dummy.next

# 下面是同样的思路，但是更加高效的实现
# 52ms 80.79%
class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = pre = ListNode(0)
        dummy.next = head
        while head and head.next:
            if head.val == head.next.val:
                while head and head.next and head.val == head.next.val:
                    head = head.next
                head = head.next
                pre.next = head
            else:
                pre = pre.next
                head = head.next
        return dummy.next