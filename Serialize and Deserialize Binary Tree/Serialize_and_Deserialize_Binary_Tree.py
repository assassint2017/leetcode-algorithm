# Runtime: 120 ms, faster than 75.17% of Python3 online submissions for Serialize and Deserialize Binary Tree.
# Memory Usage: 17.8 MB, less than 14.13% of Python3 online submissions for Serialize and Deserialize Binary Tree.

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    
    def __init__(self):
        self.index = 0

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []

        stack = []
        while root or stack:
            while root:
                res.append(str(root.val))
                stack.append(root)
                root = root.left
            res.append('#')

            if stack:
                root = stack.pop()
                root = root.right
        
        res.append('#')
        return ','.join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        node = data.split(',')
        return self.helper(node, self.index)
    
    def helper(self, node, index):
        if node[index] == '#':
            self.index += 1
            return None
    
        newnode = TreeNode(int(node[index]))
        self.index += 1
        newnode.left = self.helper(node, self.index)
        newnode.right = self.helper(node, self.index)

        return newnode

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))