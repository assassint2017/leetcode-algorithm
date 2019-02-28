# Runtime: 36 ms, faster than 50.15% of Python3 online submissions for Implement Queue using Stacks.
# Memory Usage: 13.1 MB, less than 5.32% of Python3 online submissions for Implement Queue using Stacks.

class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []
        self.topElement = None

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        if self.empty():
            self.topElement = x
        elif not self.stack1:
            while self.stack2:
                self.stack1.append(self.stack2.pop())
        self.stack1.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.stack2:
            res = self.stack2.pop()
            if self.stack2:
                self.topElement = self.stack2[-1]
            return res
        else:
            temp = self.stack1[-1]
            while len(self.stack1) != 1:
                temp = self.stack1.pop()
                self.stack2.append(temp)
            
            self.topElement = temp

            return self.stack1.pop()
        

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.topElement
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return True if not self.stack1 and not self.stack2 else False
            
# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()