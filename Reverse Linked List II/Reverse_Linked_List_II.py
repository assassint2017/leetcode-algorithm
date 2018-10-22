# 如果一个链表是55123455，要求交换的是1~4
# 那么交换顺序是
# 55213455
# 55321455
# 55432155

# 36ms 94.34%
class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        prev = dummy = ListNode(0)
        dummy.next = head
        
        for _ in range(m - 1):
            prev = prev.next
        cur = prev.next
        
        for _ in range(n - m):
            temp = cur.next
            cur.next = temp.next
            temp.next = prev.next
            prev.next = temp
        
        # 由于m有可能为1，所以不能返回head
        return dummy.next