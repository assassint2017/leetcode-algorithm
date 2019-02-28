# Runtime: 36 ms, faster than 49.11% of Python3 online submissions for Implement Stack using Queues.
# Memory Usage: 13.2 MB, less than 5.45% of Python3 online submissions for Implement Stack using Queues.

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = []
        self.queue2 = []
        self.topElement = None
        

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        if self.empty() or not self.queue2:
            self.queue1.append(x)
        else:
            self.queue2.append(x)
        
        self.topElement = x


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """

        if not self.queue1:
            send = self.queue2
            hold = self.queue1
        else:
            send = self.queue1
            hold = self.queue2
        
        res = send[0]
        while len(send) != 1:
            res = send.pop(0)
            hold.append(res)
        
        self.topElement = res 
        return send.pop(0)
        

    def top(self) -> int:
        """
        Get the top element.
        """
        return slef.topElement
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return True if not self.queue1 and not self.queue2 else False
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()