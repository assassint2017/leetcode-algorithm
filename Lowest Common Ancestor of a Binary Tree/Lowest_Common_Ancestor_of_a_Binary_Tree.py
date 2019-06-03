# Runtime: 92 ms, faster than 49.45% of Python3 online submissions for Lowest Common Ancestor of a Binary Tree.
# Memory Usage: 17.4 MB, less than 95.08% of Python3 online submissions for Lowest Common Ancestor of a Binary Tree.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        if root is None:
            return root
        
        path1, path2 = [p], [q]

        self.get_path(root, p, path1)
        self.get_path(root, q, path2)

        return self.find_ancestor(path1, path2)

    def get_path(self, root, target, path):
        
        treeStack = []
        preNode = None

        while root or treeStack:
            while root:
                treeStack.append(root)
                root = root.left
            
            if treeStack:
                root = treeStack.pop()

                if root.right is None or root.right == preNode:
                    if root.left == target or root.right == target:
                        path.append(root)
                        target = root
                        while treeStack:
                            root = treeStack.pop()
                            if (root.left == target or root.right == target):
                                path.append(root)
                                target = root
                        break

                    preNode = root
                    root = None
            
                else:
                    treeStack.append(root)
                    root = root.right
    
    def find_ancestor(self, path1, path2):

        pointer1 = len(path1) - 1
        pointer2 = len(path2) - 1

        while True:
            if pointer1 == 0 or pointer2 == 0 or path1[pointer1 - 1] != path2[pointer2 - 1]:
                break
            else:
                pointer1 -= 1
                pointer2 -= 1        
        
        return path1[pointer1]