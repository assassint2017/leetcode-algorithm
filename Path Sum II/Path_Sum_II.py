# 88ms 74.70%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        paths = []
        path = []
        treeStack = []
        lastNode = None
        temp = 0

        while root or len(treeStack) > 0:
            while root:
                temp += root.val
                path.append(root.val)

                if root.left is None and root.right is None:
                    if (temp == sum):
                        # 这里一定要注意要使用深度拷贝，否则之后的结果要被改变！！！
                        paths.append(path.copy())
                treeStack.append(root)
                root = root.left
            if len(treeStack) > 0:
                root = treeStack.pop()
                if root.right is None or root.right == lastNode:
                    temp -= root.val
                    path.pop()

                    lastNode = root
                    root = None
                else:
                    treeStack.append(root)
                    root = root.right
        return paths
        