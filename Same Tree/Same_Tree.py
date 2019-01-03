# 第一种思路 使用层次遍历依次比较各个节点
# 52ms 34.66%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        queue1 = [p]
        queue2 = [q]
        
        while queue1 and queue2:
            
            itemP = queue1.pop(0)
            itemQ = queue2.pop(0)
            
            if itemP is None or itemQ is None:
                if not itemP is itemQ is None:
                    return False
            elif not itemP.val == itemQ.val:
                return False
            else:
                queue1.append(itemP.left)
                queue1.append(itemP.right)

                queue2.append(itemQ.left)
                queue2.append(itemQ.right)
        
        # 当循环退出的时候，只有两个队列都为空的时候两棵树才是完全相等的
        return True if not queue1 and not queue2 else False