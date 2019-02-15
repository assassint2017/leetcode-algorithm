# 注意一下python中是如何实现一个链表的，比c++要容易很多

# Runtime: 56 ms, faster than 91.81% of Python3 online submissions for Min Stack.
# Memory Usage: 17 MB, less than 100.00% of Python3 online submissions for Min Stack.

class linkNode:
    def __init__(self, value):
        self.val = value
        self.next = None

class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.head = linkNode(0)
        self.minvalue = float('inf')

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if x <= self.minvalue:
            tempNode = linkNode(self.minvalue)
            if self.empty():
                self.head.next = tempNode
            else:
                tempNode.next = self.head.next
                self.head.next = tempNode
            self.minvalue = x
        
        tempNode = linkNode(x)
        if self.empty():
            self.head.next = tempNode
        else:
            tempNode.next = self.head.next
            self.head.next = tempNode
        
    def pop(self):
        """
        :rtype: void
        """
        if not self.empty():
            if self.head.next.val == self.minvalue:
                deleteNode = self.head.next
                self.head.next = deleteNode.next
                self.minvalue = self.head.next.val
            deleteNode = self.head.next
            self.head.next = deleteNode.next
        
    def top(self):
        """
        :rtype: int
        """
        return self.head.next.val
        
    def getMin(self):
        """
        :rtype: int
        """
        return self.minvalue
    
    def empty(self):
        if self.head.next is None:
            return True
        else:
            return False

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()