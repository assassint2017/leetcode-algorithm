# Runtime: 52 ms, faster than 18.21% of Python3 online submissions for Binary Tree Paths.
# Memory Usage: 13.3 MB, less than 5.44% of Python3 online submissions for Binary Tree Paths.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        res = []
        vec = []
        resint = []

        myStack = []
        preNode = None

        while root or myStack:
            while root:
                myStack.append(root)
                vec.append(root.val)
                root = root.left
            if myStack:
                root = myStack.pop()
                if root.right is None or root.right == preNode:
                    if root.left is None and root.right is None:
                        resint.append(vec[:])
                    vec.pop()

                    preNode = root
                    root = None
                else:
                    myStack.append(root)
                    root = root.right
            
        self.toString(resint, res)
        return res
    
    def toString(self, resint, res):
        for path in resint:
            res.append('->'.join([str(item) for item in path]))
