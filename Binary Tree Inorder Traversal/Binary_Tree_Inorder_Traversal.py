# 第一种思路 使用递归
# 56ms 28.98%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        values = []
        def traversal(root):
            if root is None:
                return
            else:
                traversal(root.left)
                values.append(root.val)
                traversal(root.right)
            
        traversal(root)
        return values
        
        
# 第二种思路 使用堆栈代替递归
# 52ms 41.05%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        values = []
        treeStack = []
        temp = root

        while temp or len(treeStack) > 0:
            while temp:
                treeStack.append(temp)
                temp = temp.left
            if len(treeStack) > 0:
                temp = treeStack.pop()
                values.append(temp.val)
                temp = temp.right
        return values