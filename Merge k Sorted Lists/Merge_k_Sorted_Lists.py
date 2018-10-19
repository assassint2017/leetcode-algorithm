# 第一种思路，寻找当前最小的节点，然后将一个放入新的节点内
# 不需要额外的存储空间，时间复杂度O(N)N为所有节点的个数和
# 4048ms 10.24%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        # 首先剔除空链表
        lists = [item for item in lists if isinstance(item, ListNode)]
        if not lists:
            return []
        
        temp_list = [listnode.val for listnode in lists]
        index = temp_list.index(min(temp_list))
        
        mid = head = lists[index]
        lists[index] = lists[index].next
        if lists[index] is None:
            lists.pop(index)
        
        while lists:
            temp_list = [listnode.val for listnode in lists]
            
            index = temp_list.index(min(temp_list))

            mid.next = lists[index]
            mid = mid.next
            
            lists[index] = lists[index].next
            if lists[index] is None:
                lists.pop(index)
        
        return head

# 第二种思路，根据答案的Approach 5: Merge with Divide And Conquer
# 这里需要使用自己之前写的融合两个链表的代码
# 96ms 66.31%

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if not lists:
            return lists
        interval = 1
        while interval < len(lists):
            index = 0
            while index < len(lists) - interval:
                lists[index] = self.mergeTwoLists(lists[index], lists[index + interval])
                index += 2 * interval
            interval *= 2
        return lists[0]

    def mergeTwoLists(self, l1, l2):
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