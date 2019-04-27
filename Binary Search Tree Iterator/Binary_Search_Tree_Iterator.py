# Runtime: 108 ms, faster than 23.36% of Python3 online submissions for Binary Search Tree Iterator.
# Memory Usage: 20.2 MB, less than 100.00% of Python3 online submissions for Binary Search Tree Iterator.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: 'TreeNode'):
        self.nodeStack = []
        self.push(root)

    def next(self) -> 'int':
        """
        @return the next smallest number
        """
        tempNode = self.nodeStack.pop()
        if tempNode.rihgt:
            self.push(tempNode.right)
        return tempNode.val
                
    def hasNext(self) -> 'bool':
        """
        @return whether we have a next smallest number
        """
        return not self.nodeStack

    def push(self, root):
        while root:
            self.nodeStack.append(root)
            root = root.left
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()