# Runtime: 180 ms, faster than 71.68% of Python3 online submissions for Design Linked List.
# Memory Usage: 13.5 MB, less than 10.17% of Python3 online submissions for Design Linked List.

class LinkNode:
    def __init__(self, num):
        self.val = num
        self.next = None

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.length = 0
        self.dummyhead = LinkNode(0)
        self.tail = self.dummyhead
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if 0 <= index < self.length:
            temp = self.dummyhead
            while index >= 0:
                index -= 1
                temp = temp.next
            return temp.val
        else:
            return -1

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        temp = LinkNode(val)

        if self.tail == self.dummyhead:
            self.tail = temp
        
        temp.next = self.dummyhead.next
        self.dummyhead.next = temp

        self.length += 1
        

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        temp = LinkNode(val)
        self.tail.next = temp
        self.tail = temp

        self.length += 1
        

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index < 0 or index > self.length:
            return
        elif index is 0:
            self.addAtHead(val)
        elif index == self.length:
            self.addAtTail(val)
        else:
            addNode = LinkNode(val)

            preNode = self.dummyhead
            while index > 0:
                index -= 1
                preNode = preNode.next
            
            addNode.next = preNode.next
            preNode.next = addNode

            self.length += 1
        

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0 or index >= self.length:
            return
        else:
            temp = index

            preNode = self.dummyhead
            while index > 0:
                index -= 1
                preNode = preNode.next
            
            if temp == self.length - 1:
                self.tail = preNode
            
            delNode = preNode.next
            preNode.next = delNode.next

            del delNode
            self.length -= 1
        
# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)